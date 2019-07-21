#define GLEW_STATIC

#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <chrono>

// Shader source code in GLSL.
// Stored in a const char array to be compiled later.

// Vertex shader code.
const char *vertexSource = R"glsl(
    #version 150 core

    in vec2 position;
    in vec3 color;
    out vec3 vertexColorOut;

    void main() {
        vertexColorOut = color;
        gl_Position = vec4(position, 0.0, 1.0);
    }
)glsl";


// Fragment shader code.
const char *fragmentSource = R"glsl(
    #version 150 core

    in vec3 vertexColorOut;
    out vec4 colorOut;

    void main() {
        colorOut = vec4(vertexColorOut, 1.0);
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

    sf::Window root(sf::VideoMode(800, 600), "OpenGL", sf::Style::Close, settings); // Create window

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

    // Create a vertex array.
    GLuint vertexArray;
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);

    ///* Code: *///
    float vertices[] = {
        0.0f, 0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f
    }; // Vertex list.

    // Create vertex buffer object.
    GLuint vbo; 
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Declare vertex data formatting.
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);

    GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
    glEnableVertexAttribArray(colAttrib);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));

    // Main loop.
    sf::Event event;
    bool isRunning = true;
    while (isRunning) {
        while (root.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                isRunning = false;
            }
        }
        
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        root.display();
    }

    return 0;
}