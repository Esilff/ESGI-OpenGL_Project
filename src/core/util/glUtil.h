//
// Created by Esilff on 06/04/2023.
//

#ifndef GLUTIL_H
#define GLUTIL_H
#include <glad/glad.h>
#include <iostream>

namespace GLUtil {
    inline void glDebugCallback(unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const GLchar* message, const void* userParam) {
        std::cout << "[GL Error] : " << message << std::endl;
    }
}

#endif //GLUTIL_H
