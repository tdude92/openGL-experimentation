#ifndef SHADERS_H
#define SHADERS_H

#define GLEW_STATIC

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

void checkShaderCompilation(GLuint shader, std::string shaderType) {
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::" << shaderType << "::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void checkShaderProgramLinking(GLuint shaderProgram) {
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER_PROGRAM::" << shaderProgram << "::LINK_FAILED\n" << infoLog << std::endl;
    }
}

class Shader {
    public:
        Shader(const GLchar* vertexPath, const GLchar* fragmentPath) {
            std::string vertexSource, fragmentSource;
            std::ifstream vShaderFile, fShaderFile;
            vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            try {
                vShaderFile.open(vertexPath);
                fShaderFile.open(fragmentPath);

                std::stringstream vShaderStream, fShaderStream;
                vShaderStream << vShaderFile.rdbuf();
                fShaderStream << fShaderFile.rdbuf();

                vShaderFile.close();
                fShaderFile.close();

                vertexSource = vShaderStream.str();
                fragmentSource = fShaderStream.str();
            } catch (std::ifstream::failure error) {
                std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
            }
            const char* vShaderSource = vertexSource.c_str();
            const char* fShaderSource = fragmentSource.c_str();

            // Compile shaders.
            GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertexShader, 1, &vShaderSource, NULL);
            glCompileShader(vertexShader);
            checkShaderCompilation(vertexShader, "VERTEX");

            GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragmentShader, 1, &fShaderSource, NULL);
            glCompileShader(fragmentShader);
            checkShaderCompilation(fragmentShader, "FRAGMENT");

            // Create shader program.
            id_ = glCreateProgram();
            glAttachShader(id_, vertexShader);
            glAttachShader(id_, fragmentShader);
            glLinkProgram(id_);
            checkShaderProgramLinking(id_);

            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);
        }

        void use() {
            glUseProgram(id_);
        }
        
        void setUniform_b(const std::string &name, bool value) const {
            glUniform1i(glGetUniformLocation(id_, name.c_str()), (int)value);
        }
        void setUniform_i(const std::string &name, int value) const {
            glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
        }
        void setUniform_f(const std::string &name, float value) const {
            glUniform1f(glGetUniformLocation(id_, name.c_str()), value);
        }

        GLuint id() const {
            return id_;
        }
    private:
        GLuint id_;
};

#endif