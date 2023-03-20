#pragma vertex
#version 330
layout(location=0)in vec3 aPos;
layout(location=1)in vec2 aTexCoord;
out vec2 TexCoord;


void main() {
    TexCoord = aTexCoord;
    gl_Position = vec4(aPos, 1.0);
}

#pragma fragment
#version 330
in vec2 TexCoord;
out vec4 color;

uniform sampler2D ourTexture;

void main() {

    color = texture(ourTexture, TexCoord);
}
