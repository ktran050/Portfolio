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
    float t1 = 0; float t2 = 0;		// init intersect points (our results)
    float inrad = 0; float outrad = 0;  // term inside radical and term outside
    Hit tempHit;

    // terms for readability
    vec3 v = ray.endpoint-center;
    float udv = dot(ray.direction, v);

    // calculate terms
    outrad = fabs(udv)*-1;
    inrad = sqrt( (udv*udv)-(dot(v,v) + radius*radius));

    // calculate each intersect
    t1 = outrad - inrad;
    t2 = outrad + inrad;

    if( t1 <= 0 && t2 <= 0)    // both are neg; the only case where there is no intersection
	return false;
    else if( t1 > 0 && t2 <= 0){ // t1 is pos. t2 is neg or 0
	tempHit.t = t1;
	tempHit.ray_exiting = true;;	
	tempHit.object = this;
	hits.push_back( tempHit);
	
	//hits.push_back( Hit(this, t1, false));	
    }
    else if( t1 <= 0 && t2 > 0){
	tempHit.t = t2;
	tempHit.ray_exiting = true;	
	tempHit.object = this;
	hits.push_back( tempHit);
	//hits.push_back( Hit(this, t2, true));
    }
    else{
	tempHit.t = t1;
	tempHit.ray_exiting = false;	
	tempHit.object = this;
	hits.push_back( tempHit);
	//hits.push_back( Hit(this, t1, false));

	tempHit.t = t2;
	tempHit.ray_exiting = true;	
	tempHit.object = this;
	hits.push_back( tempHit);
	//hits.push_back( Hit(this, t2, true));
    }
    return true;

}

vec3 Sphere::Normal(const vec3& point) const
{
    vec3 normal;
    // TODO: set the normal
    return normal;
}
