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

    // case both are negative
    if( (t1<0) && (t2<0))
	return false;
    // record the hits
    if(t1>0)
	tempHit
	hits_push_back(tempHit);
}

vec3 Sphere::Normal(const vec3& point) const
{
    vec3 normal;
    // TODO: set the normal
    return normal;
}
