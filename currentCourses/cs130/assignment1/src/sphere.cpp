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
        return true;
    }
}

vec3 Sphere::Normal(const vec3& point) const
{
    // CS130 
    return point - center;
}

/*
#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
bool Sphere::Intersection(const Ray& ray, std::vector<Hit>& hits) const
{
    // TODO
/*
    	vec3 w = ray.endpoint - this->center; 
	//w = w.normalized();
	vec3 v = ray.direction.normalized();
	float DotWV = dot(w, v);
	float DotWW = dot(w,w);
	//radius squared
	float RSQ = this->radius * this->radius;
//std::cerr << "w: " << w[0] << ' ' << w[1] << ' ' << w[2] << '\n';
//std::cerr << "V: " << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
//std::cerr << "SPHERE " << this->center[0] << ' ' << this->center[1] <<  ' ' << this->center[2] << '\n';
//std::cerr << "ray.endpoint " << ray.endpoint[0] << ' ' << ray.endpoint[1] << ' '  << ray.endpoint[2] << '\n'; 
//std::cerr << "DotWV: " << DotWV << "43	DotWW: " << DotWW << "	RSQ: " << RSQ << '\n';	
    Hit temp; 
    
	if((DotWV*DotWV) - DotWW + RSQ < 0.0)
	{
	   //std::cerr << "IN miss" << std::endl;
	   //RAY DOESN'T INTERSECT SPHERE
	   return false;
	}
	else if( DotWV > 0 && DotWW > RSQ )
	{
		
	   //std::cerr << "IN1" << std::endl;
	   //RAY DOESN'T INTERSECT SPHERE
	   return false;
	}
	else if( DotWV > 0 && DotWW <= RSQ )
	{
	   //RAY INTERSECT SPHERE AT {0,T1}
	   
	   //std::cerr << "IN2" << std::endl;
	   //first hit point
	   temp.object = this;
	   temp.t = 0;
	   temp.ray_exiting = false;
	   hits.push_back(temp);
	   
	   //second hit point
	   temp.object = this;
	   temp.t = -(DotWV) + sqrt( (DotWV * DotWV) - DotWW + RSQ );
	   temp.ray_exiting = true;
	   hits.push_back(temp);
	   
	   return true;   
	    
	}
	else if( DotWV <= 0 && DotWW > RSQ )
	{	
	   //RAY INTERSECT SPHERE AT {0,T1}
	   
	   std::cerr << "IN3" << ' ';
	   //first hit point
	   temp.object = this;
	   temp.t = 0;
	   temp.ray_exiting = false;
	   hits.push_back(temp);
	   
	   //second hit point
	   temp.object = this;
	   temp.t = -(DotWV) + sqrt( (DotWV * DotWV) - DotWW + RSQ );
	   temp.ray_exiting = true;
	   hits.push_back(temp);
	   
	   return true;
	}
	//else if(DotWV * DotWV - DotWW + RSQ >= 0)
	else if( DotWV <= 0 && DotWW <= RSQ )
	{
	   //RAY INTERSECT SPHERE AT {T0,T1}
	   
	   std::cerr << "IN4" << ' ';
   	   //first hit point
	   temp.object = this;
	   temp.t = -(DotWV) - sqrt( (DotWV * DotWV) - DotWW + RSQ );
	   temp.ray_exiting = false;
	   hits.push_back(temp);
	   
	   //second hit point
	   temp.object = this;
	   temp.t = -(DotWV) + sqrt( (DotWV * DotWV) - DotWW + RSQ );
	   temp.ray_exiting = true;
	   hits.push_back(temp);
	   
	   return true;
	}

   
   Hit temp; 
   
	vec3 rayDirection =  ray.direction;
	rayDirection = rayDirection.normalized();
	
	vec3 CP_SP = ray.endpoint - this->center;
	float dotCPSP = dot(CP_SP, CP_SP);			
				
				
	float a = dot(rayDirection, rayDirection);
	
	float b = 2.00 * dot(rayDirection , CP_SP);
	float c = dotCPSP - (this->radius * this->radius);
	
	if(sqrt(b * b - 4 * a * c) > 0 )
	{
//cerr << sqrt(b * b - 4 * a * c) << ' ';
		float tplus  =  (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		float tminus =  (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		if(tplus > 0 || tminus > 0)
		{
		   if(tminus < 0)
		   {
			   tminus = 0;
		   }
		   //first hit point
		   temp.object = this;
		   temp.t = tminus;
		   temp.ray_exiting = false;
		   hits.push_back(temp);
		   
		   
		   //second hit point
		   if(tplus < 0)
		   {
			   tplus = 0;
		   }
		   temp.object = this;
		   temp.t = tplus;
		   temp.ray_exiting = true;
		   hits.push_back(temp);
//std::cerr << tminus << ' ' << tplus << '\n';
		   return true; 
		}
		
	}		
     
   return false;
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
    // TODO: set the normal
    normal = point - this->center;
    
    
    return normal;
}

*/