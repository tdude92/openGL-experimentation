#version 330 core

in vec4 vColor;
in vec2 vTexCoords;

out vec4 fragmentColor;

uniform sampler2D crateTex;
uniform sampler2D coolGuyTex;

void main() {
    fragmentColor = mix(texture(crateTex, vTexCoords), texture(coolGuyTex, vTexCoords), 0.2);
}