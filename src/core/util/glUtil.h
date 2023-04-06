//
// Created by Esilff on 06/04/2023.
//

#ifndef GLUTIL_H
#define GLUTIL_H
#include <glad/glad.h>
#include <iostream>

namespace GLUtil {
    void debugCallback(unsigned int source, unsigned int type, unsigned int id, unsigned int severity, GLsizei length, const GLchar* message, const void* userParam) {
        std::cout << "[OpenGL Error] : " << message << std::endl;
    }
}

#endif //GLUTIL_H
