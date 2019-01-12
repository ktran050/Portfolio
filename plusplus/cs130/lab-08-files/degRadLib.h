#ifndef __degRadLib__
#define __degRadLib__
#define pi 3.141592653897

inline float degToRad(float deg){
    float rad;

    rad = deg*pi/180;

    return rad;
}

inline float radtoDeg(float rad){
    float deg;
  
    deg = rad*180/pi;

    return deg;
}
#endif
