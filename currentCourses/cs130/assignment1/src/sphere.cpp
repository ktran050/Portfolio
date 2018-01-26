#include "sphere.h"
#include "ray.h"


// Determine if the ray intersects with the sphere
//sphere has mem variables radius and center
//v = e-c
//e = ray endpoint
//c = center
//u = ray direction
// negative(u dot v) - sqr[(u dot v)^2 - (v dot v) + r^2]
bool Sphere::Intersection(const Ray& ray, std::vector<Hit>& hits) const
{
    //cs130
    float t1 = 0; float t2 = 0;	float t0 = 0;	// init intersect points (our results)
    Hit tempHit;

    // terms for readability
    vec3 v = ray.endpoint-center; vec3 u = ray.direction;
    float discr = dot(u,v)*dot(u,v) + radius*radius - dot(v,v);
    
    // Calculate t1 and t2
    t1 = -1*dot(u,v) + sqrt(discr);
    t2 = -1*dot(u,v) - sqrt(discr);
    
    if(discr < 0){
        return false;
    }
    else if(discr==0){
        // tangential intersection t=-b/2ac == -b/2c
        t0 = -2*dot(u,v)/(2*(dot(v,v)-radius*radius));
        if(t0 > 0){
            tempHit.t = t0;
            tempHit.object = this;
            tempHit.ray_exiting=true;
            hits.push_back(tempHit);
            
            tempHit.t = 0;
            tempHit.object = this;
            tempHit.ray_exiting=true;
            hits.push_back(tempHit);
            
        }
        return true;
    }
    else{   // discr is pos
	if(t1 && t2){
	    tempHit.object=this;
	    tempHit.t = t1;
	    tempHit.ray_exiting = false;;	
            hits.push_back(tempHit);

	    tempHit.object=this;
	    tempHit.t = t2;
	    tempHit.ray_exiting = true;
            hits.push_back(tempHit);
	}
	else{
        if(t1>0){
            tempHit.object=this;
            tempHit.t = t1;
            tempHit.ray_exiting = true;
            hits.push_back(tempHit);
        }
        if(t2>0){
            tempHit.object=this;
            tempHit.t=t2;
            tempHit.ray_exiting = true;
            hits.push_back(tempHit);
        }
	}
        return true;
    }
}

vec3 Sphere::Normal(const vec3& point) const
{
    // CS130 
    return point - center;
}
