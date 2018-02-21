#include "application.h"

//struct gl_LightSourceParameters {
//    vec4 ambient;
//    vec4 diffuse;
//   vec4 specular;
//    vec4 position;
//};
//uniform gl_LightSourceParameters gl LightSource[gl_MaxLights];
//struct gl

int main(int argc, char* argv[])
{
    int width = 640;
    int height = 480;

    application app;
    app.init(argc, argv, width, height);
    app.run();
}
