//
// Created by Esilff on 20/03/2023.
//

#ifndef ESGI_OPENGL_SHADER_H
#define ESGI_OPENGL_SHADER_H
#include <array>
#include <string>
#include <iostream>
#include <fstream>
#include <glad/glad.h>
#include "../math/vector.h"

#define SHADER_SUPPORT 2
#define DEFAULT_SHADER "src/shaders/default.glsl"

enum ShaderType {
    NONE = -1,
    VERTEX,
    FRAGMENT
};

class Shader {
    std::array<std::string, SHADER_SUPPORT> m_source;
    unsigned int m_program;

    void parseShader(const std::string &path);
    void loadShader();

public:
    Shader();
    Shader(const Shader& shader);
    explicit Shader(const std::string &path);
    ~Shader();

    void bind();
    void unbind();

    void setUniform(const std::string& name, const Vector& vector);
};


#endif //ESGI_OPENGL_SHADER_H
