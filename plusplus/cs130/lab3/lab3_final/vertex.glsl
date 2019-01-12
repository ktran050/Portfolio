void main() {
  pos = (gl_ModelViewMatrix * gl_Vertex).xyz;
  normal = normalize(glNormalMatrix * gl_Normal);
  lightDir = normalize(gl_LightSource[0].position.xyz-pos);
  gl_Position = gl_PositionMatrix * gl_ModelViewMatrix * gl_Vertex;
}
