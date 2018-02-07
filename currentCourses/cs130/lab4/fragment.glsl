uniform sampler2D tex;
varying vec3 N;
varying vec4 position;

void main()
{
    vec4 tex_color = texture2D(tex,gl_TexCoord[0].st);
    vec3 tex_ccolor; ccolor = tex_color.rgb;
    vec3 diff = vec3(gl_LightSource[0].position - position);
    vec3 L = normalize(diff);
    vec3 normal = normalize(N);

    float intensity = max(dot(L, normal),0.0);
    vec3 spec = normal*intensity*2.0 - L; 
    spec=max(dot(spec,position),0);
    gl_FragColor.rgb=tex_ccolor*(intensity * gl_LightSource[0].diffuse.rgb + gl_FrontMaterial.ambient.rgb * gl_LightSource[0].ambient.rgb + spec);
    gl_FragColor.a = 1.0;
}
