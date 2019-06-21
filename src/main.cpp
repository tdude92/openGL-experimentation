#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>
#include <SFML/Window.hpp>

int main() {
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 2;

    // OpenGL version
    settings.majorVersion = 3;
    settings.minorVersion = 2;

    settings.attributeFlags = sf::ContextSettings::Core;

    sf::Window window(sf::VideoMode(600, 600), "OpenGL", sf::Style::Close, settings);

    // Get OpenGL functionality.
    glewExperimental = GL_TRUE;
    glewInit();

    // Test.
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    std::cout << vertexBuffer << std::endl;

    bool running = true;
    while (running) {
        sf::Event windowEvent;
        while (window.pollEvent(windowEvent)) {
            switch (windowEvent.type) {
                case sf::Event::Closed:
                    running = false;
                    break;
            }
        }
    }

    return 0;
}