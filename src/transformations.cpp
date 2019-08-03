#define GLEW_STATIC

#include <SFML/Window.hpp>
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "stb_image.h"

#include "shaders.hpp"

int main() {
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 2;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    settings.attributeFlags = sf::ContextSettings::Core;

    sf::Window root(sf::VideoMode(720, 720), "Transformations", sf::Style::Close, settings);

    glewExperimental = GL_TRUE;
    glewInit();

    ///* CREATE SHADER PROGRAM *///
    Shader shader("../src/shaders/transformations.vs", "../src/shaders/transformations.fs");

    ///* GET VERTEX DATA AND SET ATTRIBUTE FORMAT *///
    float vertices[] = {
            // Position             // Color                // Tex coords
            -0.25f, 0.25f, 0.0f,    1.0f, 0.0f, 0.0f,       0.0f, 0.0f, // top left
            0.25, 0.25f, 0.0f,      0.0f, 1.0f, 0.0f,       1.0f, 0.0f, // top right
            0.25, -0.25, 0.0f,      1.0f, 1.0f, 0.0f,       1.0f, 1.0f, // bottom right
            -0.25, -0.25, 0.0f,     0.0f, 0.0f, 1.0f,       0.0f, 1.0f // bottom left
    };

    float indices[] = {
            0, 1, 3,
            1, 2, 3
    };

    GLuint vao, vbo, ebo;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8, (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8, (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    ///* LOAD TEXTURES AND SET TEX PARAMS *///
    int imgWidth, imgHeight, nrChannels;
    unsigned char* imgData;

    GLuint crateTex, coolGuyTex;
    glGenTextures(1, &crateTex);
    glGenTextures(1, &coolGuyTex);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, crateTex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    imgData = stbi_load("../src/assets/crate1_diffuse.png", &imgWidth, &imgHeight, &nrChannels, 0);
    if (imgData) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
        exit(EXIT_FAILURE);
    }
    stbi_image_free(imgData);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, coolGuyTex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    sf::Event event;
    bool running = true;
    while (running) {
        while (root.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            }
        }
        root.display();
    }

    return 0;
}