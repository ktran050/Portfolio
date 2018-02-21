void main() {
  gl_Position = gl_ProjectionMatrix 
      * gl_ModelViewMatrix
      * gl_Vertex;
  gl_FrontColor = 
      vec4(0, 1, 0, 1);
}
