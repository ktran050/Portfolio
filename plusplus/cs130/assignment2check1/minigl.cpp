/**
 * minigl.cpp
 * -------------------------------
 * Implement miniGL here.
 *
 * You may include minigl.h and any of the standard C++ libraries.
 * No other includes are permitted.  Other preprocessing directives
 * are also not permitted.  These requirements are strictly
 * enforced.  Be sure to run a test grading to make sure your file
 * passes the sanity tests.
 *
 * The behavior of the routines your are implenting is documented here:
 * https://www.opengl.org/sdk/docs/man2/
 * Note that you will only be implementing a subset of this.  In particular,
 * you only need to implement enough to pass the tests in the suite.
 */

#include "minigl.h"
#include "vec.h"
#include "mat.h"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

/**
 * Useful data types
 */
typedef mat<MGLfloat,4,4> mat4; //data structure storing a 4x4 matrix, see mat.h
typedef mat<MGLfloat,3,3> mat3; //data structure storing a 3x3 matrix, see mat.h
typedef vec<MGLfloat,4> vec4;   //data structure storing a 4 dimensional vector, see vec.h
typedef vec<MGLfloat,3> vec3;   //data structure storing a 3 dimensional vector, see vec.h
typedef vec<MGLfloat,2> vec2;   //data structure storing a 2 dimensional vector, see vec.h

/**
 * Standard macro to report errors
 */
inline void MGL_ERROR(const char* description) {
    printf("%s\n", description);
    exit(1);
}

struct Vertex{
    public:
      // member variables
      vec3 color;
      vec4 position;

      // constuctor
      Vertex(vec3 ccolor, vec4 pposition){
          color = ccolor;
          position = pposition;
      }
      Vertex(){
          color = vec3(0,0,0);
          position = vec4(0,0,0,0);
      }
};

struct Triangle{
    public:
      // member variables
      Vertex Vertex1;
      Vertex Vertex2;
      Vertex Vertex3;
 
      // constructor
      Triangle(Vertex vert1, Vertex vert2, Vertex vert3){
          Vertex1 = vert1;
          Vertex2 = vert2;
          Vertex3 = vert3;
      }

};

// Triangle/Vertex globals
vector<Vertex> curr_vertices;
vector<Triangle> triangles;
MGLpoly_mode curr_type;
vec3 curr_color;

// Matrix globals
MGLmatrix_mode matMode = MGL_MODELVIEW;
mat4 ident = { 1, 0, 0, 0,
               0, 1, 0, 0,
               0, 0, 1, 0,
               0, 0, 0, 1};
vector<mat4> projMats = {ident};
vector<mat4> modelMats = {ident};
mat4 curr_proj = ident;
mat4 curr_model = ident;

/* Get a Triangle, width, height, and data
 * rasterize the triangle by setting colors in data cs130
*/
void Rasterize_Triangle(const Triangle& tri, int width, int height, MGLpixel* data){
    // calculate the pixel coordinates of the vertices
    vec3 A = vec3((((tri.Vertex1.position[0] + 1) / 2 * width) - 0.5),
                ((tri.Vertex1.position[1] + 1) / 2 * height - 0.5),
                0 );
    vec3 B = vec3((((tri.Vertex2.position[0] + 1) / 2 * width) - 0.5),   
                ((tri.Vertex2.position[1] + 1) / 2 * height - 0.5),
                0 );
    vec3 C = vec3((((tri.Vertex3.position[0] + 1) / 2 * width) - 0.5),    
                ((tri.Vertex3.position[1] + 1) / 2 * height - 0.5),
                0 );
    float totalArea, APB, APC, BPC; 
    vec3 temp1, temp2, P, ttemp;

    // For pixel on the screen (screen is width x height)
    for(int w = 0; w < width; w++){
        for(int h = 0; h < height; h++){        
            // Current Pixel
            P[0] = w; P[1] = h;
            temp1 = B - A; temp2 = C - A;
            ttemp  = (cross(temp1, temp2));
            totalArea = ((cross(temp1, temp2)).magnitude()/2);// Total area = magnitude ((B - A) x (C - A))/2

            // Repeat for APB/ APC / BPC
            temp2 = P - A;  // temp1 = B - A still
            APB = (cross(temp1,temp2)).magnitude() /2;
            temp1 = C - A; // temp2 = P - A
            APC = (cross(temp1,temp2)).magnitude() /2;
            temp1 = B - C; temp2 = P-B;
            BPC = (cross(temp1,temp2)).magnitude() /2;

            // Make sure all the values are positive
            if(APB < 0)
                APB *= -1;
            if(APC < 0)
                APC *= -1;
            if(BPC < 0)
                BPC *= -1;
            if(totalArea < 0)
                totalArea *= -1;

            // Decide if the pixel is in the triangle and if so color the pixel
            if((APB + APC + BPC)/totalArea == 1){   // point is in the triangle
                data[w+h*width] = Make_Pixel(255,255,255);// draw
            }
        }
    }
}

mat4& topStack(){
    if(matMode == MGL_PROJECTION)
        return projMats.back();
    //if(matMode == MGL_MODELVIEW)
    else
        return modelMats.back();
}

mat4& currMat(){
    if(matMode == MGL_PROJECTION)
        return projMats.back();
    //if(matMode == MGL_MODELVIEW)
    else
        return modelMats.back();
}

/**
 * Read pixel data starting with the pixel at coordinates
 * (0, 0), up to (width,  height), into the array
 * pointed to by data.  The boundaries are lower-inclusive,
 * that is, a call with width = height = 1 would just read
 * the pixel at (0, 0).
 *
 * Rasterization and z-buffering should be performed when
 * this function is called, so that the data array is filled
 * with the actual pixel values that should be displayed on
 * the two-dimensional screen.
 */
void mglReadPixels(MGLsize width,
                   MGLsize height,
                   MGLpixel *data)
{
    // for each triangle
    for(unsigned i = 0; i < width; i++){
        for(unsigned j = 0; j < height; j++){
            data[i+j*width] = Make_Pixel(0,0,0);
        }
    }

    for(unsigned t = 0; t < triangles.size(); t++){
       Rasterize_Triangle(triangles.at(t), width, height, data); 
    }
    triangles.clear();
}

/**
 * Start specifying the vertices for a group of primitives,
 * whose type is specified by the given mode. CS130
 */
void mglBegin(MGLpoly_mode mode)
{
    switch(mode){
        case MGL_TRIANGLES:
            curr_type = mode;
            break;
        case MGL_QUADS:
            curr_type = mode;
            break;
        default:
            printf("%s\n", "ERR: [in mglBegin] mode not valid");
            break;
    }
}


/**
 * Stop specifying the vertices for a group of primitives. CS130
 */
void mglEnd()
{
    switch(curr_type){
        case MGL_TRIANGLES:
        {
            if(curr_vertices.size()%3 != 0){ 	// check if there is a valid number of vertices for triangles
                printf("%s\n", "ERR: [in mglEnd] left over vertices for triangles");
                break;
            }

            // temp variables
            Vertex vert1;
            Vertex vert2;
            Vertex vert3;

            // Create triangles based on the list of vertices
            for(unsigned i = 0; i < curr_vertices.size(); i+=3){                 
                vert1 = curr_vertices.at(i);
                vert2 = curr_vertices.at(i+1);
                vert3 = curr_vertices.at(i+2);
                triangles.push_back( Triangle(vert1,vert2,vert3));
            }
            curr_vertices.clear();
            break;
        }

        case MGL_QUADS:
        {
            if(curr_vertices.size()%4 != 0){ 	// check if there is a valid number of vertices for quads
                printf("%s\n", "ERR: [in mglEnd] left over vertices for quads");
                break;
            }
         
            // temp variables
            Vertex vert1;
            Vertex vert2;
            Vertex vert3;
            Vertex vert4;

            // Create quads based on two triangles given our vertices
            for(unsigned i = 0; i < curr_vertices.size(); i +=4){ 
                vert1 = curr_vertices.at(i);
                vert2 = curr_vertices.at(i+1);
                vert3 = curr_vertices.at(i+2);
                vert4 = curr_vertices.at(i+3);
                triangles.push_back( Triangle(vert1,vert2,vert3));
                triangles.push_back( Triangle(vert1,vert3,vert4));
            }
  
            curr_vertices.clear();
            break;

        }
        default:
            printf("%s\n", "ERR: [in mglEnd] curr_type not valid");
            break;
    }
}


/**
 * Specify a two-dimensional vertex; the x- and y-coordinates
 * are explicitly specified, while the z-coordinate is assumed
 * to be zero.  Must appear between calls to mglBegin() and
 * mglEnd(). CS130
 */
void mglVertex2(MGLfloat x,
                MGLfloat y)
{
    mglVertex3(x,y,0);
}

/**
 * Specify a three-dimensional vertex.  Must appear between
 * calls to mglBegin() and mglEnd(). CS130
 */
void mglVertex3(MGLfloat x,
                MGLfloat y,
                MGLfloat z)
{
    vec4 curr_pos = vec4(x,y,z,1);
    curr_pos = projMats.back() * modelMats.back() * curr_pos;
    curr_vertices.push_back(Vertex(curr_color, curr_pos));
}

/**
 * Set the current matrix mode (modelview or projection).
 */
void mglMatrixMode(MGLmatrix_mode mode)
{
    matMode = mode;
}

/**
 * Push a copy of the current matrix onto the stack for the
 * current matrix mode.
 */
void mglPushMatrix()
{
    if(matMode == MGL_PROJECTION)
        projMats.push_back( projMats.back());
    if(matMode == MGL_MODELVIEW)
        modelMats.push_back( modelMats.back());

}

/**
 * Pop the top matrix from the stack for the current matrix
 * mode.
 */
void mglPopMatrix()
{
    if(matMode == MGL_PROJECTION)
        projMats.pop_back();
    if(matMode == MGL_MODELVIEW)
        modelMats.pop_back();
}

/**
 * Replace the current matrix with the identity.
 */
void mglLoadIdentity()
{
    currMat() = topStack();
    currMat() = ident;
}

/**
 * Replace the current matrix with an arbitrary 4x4 matrix,
 * specified in column-major order.  That is, the matrix
 * is stored as:
 *
 *   ( a0  a4  a8  a12 )
 *   ( a1  a5  a9  a13 )
 *   ( a2  a6  a10 a14 )
 *   ( a3  a7  a11 a15 )
 *
 * where ai is the i'th entry of the array.
 */
void mglLoadMatrix(const MGLfloat *matrix)
{
    currMat() = {matrix[0], matrix[1], matrix[2], matrix[3],
                matrix[4], matrix[5], matrix[6], matrix[7],
                matrix[8], matrix[8], matrix[10], matrix[11],
                matrix[12], matrix[13], matrix[14], matrix[15]};
}

/**
 * Multiply the current matrix by an arbitrary 4x4 matrix,
 * specified in column-major order.  That is, the matrix
 * is stored as:
 *
 *   ( a0  a4  a8  a12 )
 *   ( a1  a5  a9  a13 )
 *   ( a2  a6  a10 a14 )
 *   ( a3  a7  a11 a15 )
 *
 * where ai is the i'th entry of the array.
 */
void mglMultMatrix(const MGLfloat *matrix)
{
    // Construct the matrix based on the array
    mat4 newMat;
    for(unsigned i = 0; i < 4; i++) // traverse row
        for(unsigned j = 0; j < 4; j++) // traverse columns
            newMat(i,j) = matrix[4*j+i];
    // Calculate product
    currMat() = newMat * currMat();
    std::cout << currMat() << std::endl; 
}

/**
 * Multiply the current matrix by the translation matrix
 * for the translation vector given by (x, y, z).
 */
void mglTranslate(MGLfloat x,
                  MGLfloat y,
                  MGLfloat z)
{
}

/**
 * Multiply the current matrix by the rotation matrix
 * for a rotation of (angle) degrees about the vector
 * from the origin to the point (x, y, z).
 */
void mglRotate(MGLfloat angle,
               MGLfloat x,
               MGLfloat y,
               MGLfloat z)
{
}

/**
 * Multiply the current matrix by the scale matrix
 * for the given scale factors.
 */
void mglScale(MGLfloat x,
              MGLfloat y,
              MGLfloat z)
{
}

/**
 * Multiply the current matrix by the perspective matrix
 * with the given clipping plane coordinates.
 */
void mglFrustum(MGLfloat left,
                MGLfloat right,
                MGLfloat bottom,
                MGLfloat top,
                MGLfloat near,
                MGLfloat far)
{
}

/**
 * Multiply the current matrix by the orthographic matrix
 * with the given clipping plane coordinates.
 */
void mglOrtho(MGLfloat left,
              MGLfloat right,
              MGLfloat bottom,
              MGLfloat top,
              MGLfloat near,
              MGLfloat far)
{
    float tx = right+left / right-left;
    float ty = top+bottom / top-bottom;
    float tz = far+near / far-near;

    float x = 2/right-left;
    float y = 2/top-bottom;
    float z = -2/far-near;

    // TODO: figure out the push/pop
    mat4 orthoMat = {{x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, -tx, -ty, -tz, 1}};
    topStack() = orthoMat * topStack();
}

/**
 * Set the current color for drawn shapes.
 */
void mglColor(MGLfloat red,
              MGLfloat green,
              MGLfloat blue)
{
    curr_color = vec3(red,green,blue);
}
