#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>
#include <SFML/Window.hpp>

// Shader source code in GLSL.
// Stored in a const char array to be compiled later.

// Vertex shader code.
const char *vertexSource = R"glsl(
    #version 150 core

    in vec2 position;

    void main() {
        gl_Position = vec4(position, 0.0, 1.0);
    }
)glsl";


// Fragment shader code.
const char *fragmentSource = R"glsl(
    #version 150 core

    out vec4 outColour;

    void main() {
        outColour = vec4(1.0, 1.0, 1.0, 1.0);
    }
)glsl";


int main() {
    // Define OpenGL context settings.
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 2;

    // OpenGL version
    settings.majorVersion = 3;
    settings.minorVersion = 2;

    settings.attributeFlags = sf::ContextSettings::Core;

    sf::Window window(sf::VideoMode(600, 600), "OpenGL", sf::Style::Close, settings); // Create window

    // Get OpenGL functionality.
    glewExperimental = GL_TRUE;
    glewInit();
    
    // Compile shaders.
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    // Link shaders (Create a program).
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);


    ///* Code: *///
    float vertices[] = {
        0.0, 0.5,
        0.5, -0.5,
        -0.5, 0.5
    };

    GLuint vbo; 
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    // Event loop.
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