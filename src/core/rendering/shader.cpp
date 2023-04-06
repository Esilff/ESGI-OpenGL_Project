//
// Created by Esilff on 20/03/2023.
//

#include "shader.h"

Shader::Shader() {
    parseShader(DEFAULT_SHADER);
    loadShader();
}

Shader::Shader(const Shader& shader) : m_source(shader.m_source), m_program(shader.m_program) {
    loadShader();
}

Shader::Shader(const std::string &path) {
    parseShader(path);
    loadShader();
}

Shader::~Shader() {
    /*unbind();
    glDeleteProgram(m_program);*/
}

void Shader::bind() {
    glUseProgram(m_program);
}

void Shader::unbind() {
    glUseProgram(0);
}

void Shader::parseShader(const std::string &path) {
    std::array<std::string, SHADER_SUPPORT> sources;
    std::ifstream file(std::string(SOURCE_DIR) + "/" + path);
    if (!file.is_open()) {
        std::cout << "No shader found at : " << path << std::endl;
    }
    std::string line;
    ShaderType index = NONE;
    while (std::getline(file, line)) {
        if (line.find("#pragma") != std::string::npos) {
            if (line.find("vertex") != std::string::npos) index = VERTEX;
            if (line.find("fragment") != std::string::npos) index = FRAGMENT;
            continue;
        }
        sources[index].append(line + "\n");
    }
    m_source = sources;
}

void Shader::loadShader() {
    const char* vs = m_source[0].c_str();
    const char* fs = m_source[1].c_str();
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vs, nullptr);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cout << "Could not compile the vertexShader :\n" << infoLog << std::endl;
    }
    //compiling fragmentShader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fs, nullptr);
    glCompileShader(fragmentShader);
    int fragSuccess;
    char fragInfoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragSuccess);
    if (!fragSuccess) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, fragInfoLog);
        std:: cout << "Could not compile the fragmentShader :\n" << fragInfoLog << std::endl;
    }
    m_program = glCreateProgram();
    glAttachShader(m_program, vertexShader);
    glAttachShader(m_program, fragmentShader);
    glLinkProgram(m_program);

    glGetProgramiv(m_program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(m_program, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}