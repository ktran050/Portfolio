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
    ambientLight = (world.ambient_color+color_ambient)*world.ambient_intensity;
    return ambientLight+diffuseLight+specularLight;
}
