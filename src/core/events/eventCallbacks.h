//
// Created by Esilff on 06/04/2023.
//

#ifndef EVENTCALLBACKS_H
#define EVENTCALLBACKS_H
#include <GLFW/glfw3.h>
#include "Keyboard.h"
#include "Mouse.h"

inline void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Keyboard::getInstance()[key] = action;
}

inline void mousePosCallback(GLFWwindow* window, double xpos, double ypos) {
    Mouse::getInstance().m_lastX = Mouse::getInstance().m_xPos;
    Mouse::getInstance().m_lastY = Mouse::getInstance().m_yPos;
    Mouse::getInstance().m_xPos = xpos;
    Mouse::getInstance().m_yPos = ypos;
    Mouse::getInstance().isDragging = Mouse::getInstance()[0] == 1 || Mouse::getInstance()[1] == 1 || Mouse::getInstance()[2] == 1;
}

inline void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    Mouse::getInstance().mouseKeys[button] = action;
}

inline void mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
    Mouse::getInstance().m_scrollX = xOffset;
    Mouse::getInstance().m_scrollY = yOffset;
}

inline void windowFrameBufferSizeCallback(GLFWwindow * window, int width, int height) {
    glViewport(0,0,width, height);
}

#endif //EVENTCALLBACKS_H
