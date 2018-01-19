#include <vector>
#include "render_world.h"
#include "flat_shader.h"
#include "object.h"
#include "light.h"
#include "ray.h"
#include <limits>


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

// Find the closest object of intersection and return the object that was
// intersected.  Record the Hit structure in hit.  If no intersection occurred,
// return NULL.  Note that in the case of a Boolean, the object returned will be
// the Boolean, but the object stored in hit will be the underlying primitive.
// Any intersection with t<=small_t should be ignored.
Object* Render_World::Closest_Intersection(const Ray& ray,Hit& hit)
{
    //CS164
    //Set min_t to a large value
    Hit* closest = NULL;
    int min_t = std::numeric_limits<int>::max();
    for(unsigned i = 0; i < objects.size(); i++){
	std::vector<Hit> hitList;
	hitList.clear();
	objects[i]->Intersection(ray, hitList);	// if the object is a hit with the ray push it back
	
	closest = &hitList[0];	
	// for each hit in hitList
	for(unsigned b = 0; b < hitList.size(); b++){
	    if(hitList[i].t < closest->t && hitList[i].t > small_t){	// new closer hit
	    	closest = &hitList[i];
	    	hit = closest;// set hit to h
	    	min_t = closest->t;	// update min_t
	    }
	}
    }
    return &hit;
}

// set up the initial view ray and call
void Render_World::Render_Pixel(const ivec2& pixel_index)
{
    Ray ray;
    //CS164: init ray with endpoint (camera position) and world position 
    ray = Ray(camera.position, camera.World_Position(pixel_index));
    vec3 color=Cast_Ray(ray,1);
    camera.Set_Pixel(pixel_index,Pixel_Color(color));
}

void Render_World::Render()
{
    for(int j=0;j<camera.number_pixels[1];j++)
        for(int i=0;i<camera.number_pixels[0];i++)
            Render_Pixel(ivec2(i,j));
}

// cast ray and return the color of the closest intersected surface point,
// or the background color if there is no object intersection
vec3 Render_World::Cast_Ray(const Ray& ray,int recursion_depth)
{
    // TODO
    vec3 color;

    // determine the color here

    return color;
}
