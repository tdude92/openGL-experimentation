#define GLEW_STATIC

#include <GL/glew.h>
#include <SFML/Window.hpp>

#include <cstdlib>
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

    sf::Window root(sf::VideoMode(720, 720), "Textures", sf::Style::Close, settings);

    glewExperimental = GL_TRUE;
    glewInit();

    ///* CREATE SHADER PROGRAMS *///
    Shader shader("shaders/textures.vs", "shaders/textures.fs");

    float vertices[] = {
        // Positions            // Colors               // Texture coords
        -0.5f, 0.5f, 0.0f,      1.0f, 0.0f, 0.0f,       0.0f, 1.0f, // Top left
        0.5f, 0.5f, 0.0f,       0.0f, 1.0f, 0.0f,       1.0f, 1.0f, // Top right
        0.5f, -0.5f, 0.0f,      1.0f, 0.0f, 0.0f,       1.0f, 0.0f, // Bottom right
        -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f,       0.0f, 0.0f, // Bottom left
    };

    unsigned int indices[] = {
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
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    ///* LOAD TEXTURES *///
    GLuint crateTex;
    glGenTextures(1, &crateTex);
    glBindTexture(GL_TEXTURE_2D, crateTex);

    // Set texture wrapping style.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Set texture filtering method.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int imgWidth, imgHeight, nrChannels;
    unsigned char* imgData = stbi_load("assets/crate1_diffuse.png", &imgWidth, &imgHeight, &nrChannels, 0);

    if (imgData) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imgData);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
        exit(EXIT_FAILURE);
    }
    stbi_image_free(imgData);

    sf::Event event;
    bool running = true;
    while (running) {
        while(root.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            }
        }
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindTexture(GL_TEXTURE_2D, crateTex);

        shader.use();
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        root.display();
    }
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
}