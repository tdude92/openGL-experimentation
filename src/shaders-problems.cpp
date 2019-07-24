#define GLEW_STATIC

#include <GL/glew.h>
#include <SFML/Window.hpp>

#include <cmath>
#include <chrono>

#include "shaders.hpp"


int main() {
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 2;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    settings.attributeFlags = sf::ContextSettings::Core;

    sf::Window root(sf::VideoMode(1280, 720), "Shaders Problems", sf::Style::Close, settings);

    glewExperimental = GL_TRUE;
    glewInit();

    Shader shader("shaders/shaders-problems.vs", "shaders/shaders-problems.fs");

    float vertices[] = {
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };
    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    auto tStart = std::chrono::high_resolution_clock::now();
    sf::Event event;
    bool running = true;
    while (running) {
        while (root.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            }
        }
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        auto tNow = std::chrono::high_resolution_clock::now();
        float time = std::chrono::duration_cast<std::chrono::duration<float>>(tNow - tStart).count();
        shader.setUniform_f("horizontalOffset", sin(time * 4) / 2);

        shader.use();
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        root.display();
    }

    return 0;
}