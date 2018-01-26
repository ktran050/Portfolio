#include "plane.h"
#include "ray.h"
#include <cfloat>
#include <limits>


// Intersect with the half space defined by the plane.  The plane's normal
// points outside.  If the ray starts on the "inside" side of the plane, be sure
// to record a hit with t=0 as the first entry in hits.
bool Plane::
Intersection(const Ray& ray, std::vector<Hit>& hits) const
{
    // CS130
    Hit hit;
    hit.object=this;
    float x1raynormaldot = dot(ray.endpoint-x1, normal);

    float angle = dot(ray.direction, normal);	// angle between the ray and the normal of the plane
    if( x1raynormaldot <= 0){
      if(angle > 0){	// ray leaves
	  hit.t = 0; hit.ray_exiting = false;
	  hits.push_back(hit);

	  hit.ray_exiting = true;
	  hit.t = -1* x1raynormaldot / angle ;
	  hits.push_back(hit);
	  return true;
      }
      else{	// ray never leaves or is inside the plane
	  hit.t = 0; hit.ray_exiting = false;
	  hits.push_back(hit);

	  hit.t = std::numeric_limits<double>::max();
	  hits.push_back(hit);
	  return true;
      }

    }
    else{
	if(angle < 0){	
	  hit.t = -1* x1raynormaldot / angle ;
	  hit.ray_exiting = false;
	  hits.push_back(hit);

	  hit.ray_exiting = false;
	  hit.t = std::numeric_limits<double>::max();
	  hits.push_back(hit);
	  return true;
	}
	else{
	  return false;
	}
    }
}

vec3 Plane::
Normal(const vec3& point) const
{
    return normal;
}

