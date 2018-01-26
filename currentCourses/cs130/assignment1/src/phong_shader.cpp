#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"
#include "math.h"

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& same_side_normal,int recursion_depth,bool is_exiting) const 
{
    vec3 ambientLight, diffuseLight, specularLight;
    vec3 N = same_side_normal.normalized();
    // CS130
    // ambientLight is world.ambient_color, color_ambient, world.ambient_intensity
    ambientLight = world.ambient_color*color_ambient*world.ambient_intensity;

    for(unsigned i = 0; i < world.lights.size(); i++){
	vec3 dist = intersection_point-world.lights[i]->position;	// Ray between light and intersection 
	vec3 L = world.lights[i]->Emitted_Light(ray);
	L = L/dist.magnitude_squared();				// color of light is proportional to distance^2
	
	dist = world.lights[i]->position - intersection_point; dist = dist.normalized();
	float diffuseIntensity = 0;	// set diffuseIntensity
	diffuseIntensity = dot(dist,N);
	if(diffuseIntensity < 0) diffuseIntensity = 0;// make sure its not negative

        float specularIntensity = 0;	// set specularIntensity
	vec3 ttemp = (intersection_point - ray.endpoint).normalized();
	vec3 refDir = (dist-N*(dot(dist,N)*2)).normalized();	// reflected light direction
	specularIntensity = pow(dot(ttemp,refDir), specular_power);
	if(specularIntensity < 0){ specularIntensity = 0; }	// if neg make it 0

//	if(world.enable_shadows == false){	// if shadows disabled just immediately add values
	    diffuseLight += L*color_diffuse*diffuseIntensity;
	    specularLight += L*color_specular*specularIntensity;
//	}
//	else{
//	    if(){ // only if no objects block the light
//	        diffuseLight += L*color_diffuse*diffuseIntensity;
//	        specularLight += L*specularIntensity;
//	    }
    }
	

    
    	// diffuseLight is color_diffuse, diffuse_intensity, light color/
    	// (distance which is light - intersection)^2
    	// magnitude of a vector  = sqrt( dot(n,n));
    	// light color = Emitted_Light(any ray)
    // specularLight
    // specular intensity, light color/(distance which is light-intersection)^2
    	// R=(2dot(L,N)*N-L)
    	// specular intensity = max(dot(R,C),0)^a (a == specular_power) 
    // shadows
    //return ambientLight+diffuseLight+specularLight;
    return ambientLight + diffuseLight + specularLight;
}
