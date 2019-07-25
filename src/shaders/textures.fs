#version 330 core

in vec4 vColor;
in vec2 vTexCoords;

out vec4 fragmentColor;

uniform sampler2D crateTex;

void main() {
    fragmentColor = texture(crateTex, vTexCoords);
}