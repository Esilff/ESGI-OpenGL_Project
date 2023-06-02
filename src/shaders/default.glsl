#pragma vertex
#version 330
layout(location=0)in vec3 aPos;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

out vec3 vPos;

void main() {
    vPos = aPos;
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(aPos, 1.0);
}

#pragma fragment
#version 330
out vec4 color;
in vec3 vPos;


void main() {
    color = vec4(vPos, 1.0);
}
