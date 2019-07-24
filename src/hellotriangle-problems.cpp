#define GLEW_STATIC

#include <GL/glew.h>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <cstdlib>


// Shaders.
const char* vertexSource = R"glsl(
    #version 330 core

    layout (location = 0) in vec3 position;

    void main() {
        gl_Position = vec4(position.x, position.y, position.z, 1.0f);
    }
)glsl";

const char* fragmentSource = R"glsl(
    #version 330 core
    
    out vec4 fragColor;

    void main() {
        fragColor = vec4(1.0f, 0.5f, 0.0f, 1.0f);
    }
)glsl";

void checkShaderCompilation(GLuint shader, std::string shaderType) {
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::" << shaderType << "::COMPILATION_FAILED\n" << infoLog << std::endl;
        exit(EXIT_FAILURE);
    }
}

void checkShaderProgramLinking(GLuint shaderProgram) {
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER_PROGRAM::" << shaderProgram << "::LINK_FAILED\n" << infoLog << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 2;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    settings.attributeFlags = sf::ContextSettings::Core;

    sf::Window root(sf::VideoMode(1280, 720), "Hello Triangle Problem 1", sf::Style::Close, settings);

    glewExperimental = GL_TRUE;
    glewInit();

    // Compile + Link shaders.
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    checkShaderCompilation(vertexShader, "VERTEX");

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    checkShaderCompilation(fragmentShader, "FRAGMENT");

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    checkShaderProgramLinking(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
        -0.5f, 0.5f, 0.0f,
        -0.25f, -0.5f, 0.0f,
        -0.75f, -0.5f, 0.0f, // Left triangle.
        0.5f, 0.5f, 0.0f,
        0.75f, -0.5f, 0.0f,
        0.25f, -0.5f // Right triangle.
    };

    // Create vbo and vao.
    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Define attributes.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind vbo and vao.
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    sf::Event event;
    bool running = true;
    while (running) {
        while (root.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            }
        }
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        root.display();
    }

    return 0;
}