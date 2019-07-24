#version 330 core

uniform float horizontalOffset;
layout (location = 0) in vec3 position;
out vec3 vertexColor;

void main() {
    gl_Position = vec4(position.x + horizontalOffset, -position.y + horizontalOffset, position.z, 1.0f);
    vertexColor = vec3(position.x + horizontalOffset, -position.y + horizontalOffset, position.z);
}