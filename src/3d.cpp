#define GLEW_STATIC

#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <cstdlib>
#include <iostream>
#include "stb_image.h"

#include "shaders.hpp"

int screenWidth = 720;
int screenHeight = 720;

int main() {
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 2;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    settings.attributeFlags = sf::ContextSettings::Core;

    sf::Window root(sf::VideoMode(screenWidth, screenHeight), "3D!", sf::Style::Default, settings);

    glewExperimental = GL_TRUE;
    glewInit();

    glViewport(0, 0, screenWidth, screenHeight);

    // Enable depth testing.
    glEnable(GL_DEPTH_TEST);

    // Create shader program.
    Shader shader("../src/shaders/3d.vs", "../src/shaders/3d.fs");

    // Define local space coordinates of an object.
    float vertices[] = {
        // Position             // Tex Coords
        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,    0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,    1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,    1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,    1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,    1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,    1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,    0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,    0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,    1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,    1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,    0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,    0.0f, 1.0f
    };

    // Create objects.
    GLuint vao, vbo;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Load textures.
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
        std::cout << "Failed to load image \"crate1_diffuse.png\"." << std::endl;
        exit(EXIT_FAILURE);
    }
    stbi_image_free(imgData);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, coolGuyTex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    imgData = stbi_load("../src/assets/coolguy.jpeg", &imgWidth, &imgHeight, &nrChannels, 0);
    if (imgData) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imgData);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load image \"coolguy.jpeg\"." << std::endl;
        exit(EXIT_FAILURE);
    }
    stbi_image_free(imgData);

    shader.use();
    shader.setUniform_i("crateTex", 0);
    shader.setUniform_i("coolGuyTex", 1);

    sf::Clock clock;
    sf::Event event;
    bool running = true;
    while (running) {
        while (root.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            } else if (event.type == sf::Event::Resized) {
                screenWidth = event.size.width;
                screenHeight = event.size.height;
                glViewport(0, 0, screenWidth, screenHeight);
            }
        }
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, crateTex);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, coolGuyTex);

        glBindVertexArray(vao);

        // Transformations.
        sf::Time elapsed = clock.getElapsedTime();
        glm::mat4 model(1.0f), view(1.0f), projection;

        model = glm::rotate(model, elapsed.asSeconds() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        projection = glm::perspective(glm::radians(45.0f), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);

        glUniformMatrix4fv(glGetUniformLocation(shader.id(), "model"), 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(glGetUniformLocation(shader.id(), "view"), 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(glGetUniformLocation(shader.id(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));

        // Drawing vertices.
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);

        root.display();
    }
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    return 0;
}