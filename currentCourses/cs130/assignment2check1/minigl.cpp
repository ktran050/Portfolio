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


/* CS130
 * Useful global variables
*/
MGLpoly_mode curr_type;
vec3 curr_color;
vector<Vertex> curr_vertices;
vector<Triangle> triangles;
//ModelView;
//Projection;

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
    //   transform to pixel coord
    for(unsigned w = 0; w < width; w++){
        for(unsigned h = 0; h < height; h++){
            curr_color = curr_color;
		// p = (w,h)
		// a, b, c
		// alpha, beta, gamma
		// if (...>0)
		// 	draw the pixel
        }
    }
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
                vert2 = curr_vertices.at(i+2);
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

/* Get a Triangle, width, height, and data
 * rasterize the triangle by setting colors in data cs130
*/
void Rasterize_Triangle(const Triangle& tri, int width, int height, MGLpixel* data){
    // calculate the pixel coordinates of the vertices
    // For pixel on the screen (screen is width x height)
    // Calculate the barycentric coordinate of the pixel (Suggestion: use a helper function that calculates the area of a triangle given vertices)
    // Decide if the pixel is in the triangle and if so color the pixel
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
    curr_vertices.push_back(Vertex(curr_color,vec4(x,y,z,1))); // push back with curr_color and coords given
}

/**
 * Set the current matrix mode (modelview or projection).
 */
void mglMatrixMode(MGLmatrix_mode mode)
{
}

/**
 * Push a copy of the current matrix onto the stack for the
 * current matrix mode.
 */
void mglPushMatrix()
{
}

/**
 * Pop the top matrix from the stack for the current matrix
 * mode.
 */
void mglPopMatrix()
{
}

/**
 * Replace the current matrix with the identity.
 */
void mglLoadIdentity()
{
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
