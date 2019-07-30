#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoords;

out vec4 vColor;
out vec2 vTexCoords;

void main() {
    gl_Position = vec4(pos, 1.0f);
    vColor = vec4(color, 1.0f);
    vTexCoords = texCoords;
}
