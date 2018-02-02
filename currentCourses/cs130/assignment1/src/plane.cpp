
#include "plane.h"
#include "ray.h"
#include <cfloat>


// Intersect with the half space defined by the plane.  The plane's normal
// points outside.  If the ray starts on the "inside" side of the plane, be sure
// to record a hit with t=0 as the first entry in hits.
bool Plane::
Intersection(const Ray& ray, std::vector<Hit>& hits) const
{
    // CS130
    Hit hit;
    hit.object=this;
    hit.ray_exiting = true;

    float nraydot = dot(normal, ray.direction);
    float tmpT = dot(normal, x1-ray.endpoint)/nraydot;

    if(nraydot == 0){
	hit.t=0;
	hits.push_back(hit);
	return true;
    }
    else{
	if(tmpT > 0){
	    hit.t = tmpT;
	    hits.push_back(hit);
	    return true;
	}
	else{ return false;}
    }

    return false;
}

vec3 Plane::
Normal(const vec3& point) const
{
    return normal;
}
