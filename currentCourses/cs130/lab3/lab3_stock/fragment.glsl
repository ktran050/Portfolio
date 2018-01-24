vec4 light_color = vec4(1, 1, 1, 1);

void main() {
  gl_FragColor = gl_Color * light_color;
}
