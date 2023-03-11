#version 120 core
attribute vec3 aPos;
attribute vec3 aCol;
varying vec3 vCol;

void main() {
    vCol = aCol;
    gl_Position = vec4(aPos, 1.0);
}