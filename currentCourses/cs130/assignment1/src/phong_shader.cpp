#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& same_side_normal,int recursion_depth,bool is_exiting) const 
{
    vec3 ambientLight, diffuseLight, specularLight;
    // CS130
    // ambientLight is world.ambient_color, color_ambient, world.ambient_intensity
    ambientLight = (world.ambient_color+color_ambient)*world.ambient_intensity;
    	// diffuseLight is color_diffuse, diffuse_intensity, light color/
    	// (distance which is light - intersection)^2
    	// light color = Emitted_Light(any ray)
    // specularLight
    // specular intensity, light color/(distance which is light-intersection)^2
    	// R=(2dot(L,N)*N-L)
    	// specular intensity = max(dot(R,C),0)^a (a == specular_power) 
    // shadows
    return ambientLight+diffuseLight+specularLight;
}
