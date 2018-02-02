/*
#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"
#include <math.h>
#include <iostream>

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& same_side_normal,int recursion_depth,bool is_exiting) const 
{
    vec3 color, ambLight, specLight, diffLight; // color of light and its components
    vec3 N = same_side_normal;
    vec3 incidentVector = ray.endpoint - intersection_point;
    // variables to compute
    vec3 L_color, reflectedDir, L_normed, L;
    double L_dist, specIntense, diffIntense;

    ambLight = color_ambient * world.ambient_color * world.ambient_intensity;
    for(auto T : world.lights){

        L = T->position - intersection_point; 
        L_dist = L.magnitude_squared();
        L_color = T->Emitted_Light(ray);
        L_normed = L.normalized();
        reflectedDir = (dot(N,L_normed)*2*N-L_normed).normalized();

        specIntense = std::max(dot(L_normed,N),0.0);
        diffIntense = std::pow(std::max(dot(reflectedDir,incidentVector),0.0), specular_power);
   
        specLight += color_specular * specIntense * L_color/L_dist;
        diffLight += color_diffuse * diffIntense * L_color/L_dist;    
    }


    color = ambLight + specLight + diffLight;
    return color;
}
*/

///*
#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
            const vec3& same_side_normal,int recursion_depth,bool is_exiting) const 
{
    Hit h;
    double dist;
    Ray lightray;
    vec3 color, ambient, diffuse, specular;
    vec3 L, L_norm, L_color, e, reflectRay;
    vec3 N = same_side_normal;

    // calculate each piece of color
    ambient = world.ambient_color * this->color_ambient * world.ambient_intensity;
    for (auto T : world.lights) {
        L = T->position - intersection_point;
        L_color = T->Emitted_Light(ray);
        reflectRay = (2*dot(L.normalized(),N)*N - L.normalized());
        e = (ray.endpoint - intersection_point).normalized();
        dist = L.magnitude_squared();
        L_norm = L.normalized();

        if(world.enable_shadows) {
            lightray.endpoint = intersection_point; 
            lightray.direction = (T->position - intersection_point).normalized();
            if(world.Closest_Intersection(lightray,h)){                                                                                             
                if( h.t < sqrt(dist)) {
                    continue;
                }
            }   
        }

        diffuse += std::max(dot(L_norm,N),0.0) * color_diffuse * (L_color/dist);            
        specular += std::pow(std::max( dot(reflectRay,e), 0.0),specular_power) * color_specular * (L_color/dist);
    }

    color = ambient + diffuse + specular;
    return color;
}
//*/
