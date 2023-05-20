#pragma vertex
#version 330
layout(location=0)in vec3 aPos;
layout(location=1)in vec4 aColor;
out vec4 vCol;

void main() {
    vCol = aColor;
    gl_Position = vec4(aPos, 1.0);
}

#pragma fragment
#version 330
in vec4 vCol;
out vec4 color;
uniform vec3 u_Color;

void main() {
    color = vec4(u_Color, 1.0);
}
