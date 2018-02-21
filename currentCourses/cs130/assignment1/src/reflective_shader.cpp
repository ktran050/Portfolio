/*#include "reflective_shader.h"
#include "ray.h"
#include "render_world.h"

vec3 Reflective_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& same_side_normal,int recursion_depth,bool is_exiting) const
{
    vec3 color, reflect, view;
    vec3 n = same_side_normal;
    view = world.camera.position - intersection_point;
    reflect = view - 2*dot(view,n)*n;


    for(unsigned int i = 0; i < sizeof(world.lights); ++i){
        vec3 L = 

    return color = color * reflect;
}
*/
#include "reflective_shader.h"
#include "ray.h"
#include "render_world.h"
#include "light.h"

vec3 Reflective_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
            const vec3& same_side_normal,int recursion_depth, bool ray_exiting) const
{
        vec3 color;

            int rec_cou = recursion_depth;

                vec3 reflect(0,0,0);
                    
                         vec3 N = same_side_normal;
                    
                             for(unsigned int i = 0; i < world.lights.size(); i++){
                              vec3 light_position = world.lights[i]->position;
                                  //vec3 light_color = world.lights[i]->color;
                    
                                      vec3 L = (light_position - intersection_point).normalized();
                                          vec3 V = (-ray.direction).normalized();
                    
                                              //double cos_a = dot(N, L);
                                                  //vec3 B = cos_a * N;
                                                     //vec3 A = L - B;
                   
                                                         vec3 R = (-L + 2.0 * (dot(L, N)) * N).normalized();
                   
                                                             if(rec_cou <= 0){
                                                                     reflect += vec3(0,0,0);
                                                                             continue;
                                                                                 }
                    
                                                                                      if(R[0] == V[0] && R[1] == V[1] && R[2] == V[2] && rec_cou > 0){
                                                                                             rec_cou--;
                                                                                                 reflect += (1 - reflectivity) * shader->Shade_Surface(ray, intersection_point, N, recursion_depth, true);
                                                                                                     }
                   
                                                                                                         }
                    
                                                                                                              color = reflect;
                                                                                                                  //std::cout << "reflective shader - reflective_shader.cpp" << std::endl;
                                                                                                                      return color;
                                                                                                                      }
