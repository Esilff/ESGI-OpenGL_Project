//
// Created by Esilff on 06/04/2023.
//

#ifndef EVENTCALLBACKS_H
#define EVENTCALLBACKS_H
#include <GLFW/glfw3.h>
#include "Keyboard.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Keyboard::getInstance()[key] = action;
}

#endif //EVENTCALLBACKS_H
