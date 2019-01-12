
#include <vector>
#include "render_world.h"
#include "flat_shader.h"
#include "object.h"
#include "light.h"
#include "ray.h"
#include <limits>
#include "sphere.h"
#include <iostream>


Render_World::Render_World()
    :background_shader(0),ambient_intensity(0),enable_shadows(true),
    recursion_depth_limit(3),disable_fresnel_reflection(false),disable_fresnel_refraction(false)
{}

Render_World::~Render_World()
{
    delete background_shader;
    for(size_t i=0;i<objects.size();i++) delete objects[i];
    for(size_t i=0;i<lights.size();i++) delete lights[i];
}

// set up the initial view ray and call
void Render_World::Render_Pixel(const ivec2& pixel_index)
{
    Ray ray;
    //CS130: init ray with endpoint (camera position) and world position 
    ray = Ray(camera.position, (camera.World_Position(pixel_index)-camera.position).normalized());
//    ray = Ray(camera.position, (camera.position-camera.World_Position(pixel_index)).normalized());
    vec3 color=Cast_Ray(ray,1);
    camera.Set_Pixel(pixel_index,Pixel_Color(color));
}

void Render_World::Render()
{
    for(int j=0;j<camera.number_pixels[1];j++)
        for(int i=0;i<camera.number_pixels[0];i++)
            Render_Pixel(ivec2(i,j));
}

Object* Render_World::Closest_Intersection(const Ray& ray,Hit& hit)
{
    //CS130
    //Set min_t to a large value
    Object* closest = NULL; // value to be returned
    float min_t = std::numeric_limits<float>::max();
    
    for(unsigned i = 0; i < objects.size(); i++){
    	std::vector<Hit> hitList;
    	if( objects[i]->Intersection(ray, hitList)){	// if the object is a hit with the ray push it back
        	// for each hit in hitList
        	for(unsigned b = 0; b < hitList.size(); b++){
        	    if(hitList[b].t < min_t && hitList[b].t > small_t){	// new closer hit
        	    	closest = objects[i];
        	    	hit = hitList[b];// set hit to h
        	    	min_t = hitList[b].t;	// update min_t
        	    }
        	}
	    }
    }
    return closest;
}


// cast ray and return the color of the closest intersected surface point,
// or the background color if there is no object intersection
vec3 Render_World::Cast_Ray(const Ray& ray,int recursion_depth)
{
    //cs130
    vec3 color, dummy, normal;
    Hit hit;
    Object* obj = Closest_Intersection(ray, hit);

    // if intersection
    if(obj  && (recursion_depth <= recursion_depth_limit)){
        normal = obj->Normal(ray.Point(hit.t));
    	color=obj->material_shader->Shade_Surface(ray, ray.Point(hit.t), normal, recursion_depth, hit.ray_exiting);
    }
    else{
    	// call background_shader
    	color = background_shader->Shade_Surface(ray, dummy, dummy, 1, false);
    }    

    return color;
}
