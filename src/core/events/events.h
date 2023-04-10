//
// Created by Esilff on 06/04/2023.
//

#ifndef EVENTS_H
#define EVENTS_H
#include <GLFW/glfw3.h>
#include "../window.h"
#include "Keyboard.h"
namespace Events {
    bool getKey(int keycode) {
        return Keyboard::getInstance()[keycode] == GLFW_PRESS;
    }

    bool getKeyDown(int keycode) {
        bool val = Keyboard::getInstance()[keycode] == GLFW_PRESS;
        if (val) Keyboard::getInstance()[keycode] = -1;
        return val;
    }

    bool getKeyUp(int keycode) {
        bool val = Keyboard::getInstance()[keycode] == GLFW_RELEASE;
        Keyboard::getInstance()[keycode] = -1;
        return val;
    }

    bool mouseButtonDown(int button) {
        bool val = Mouse::getInstance()[button] == GLFW_PRESS;
        if (val) Mouse::getInstance()[button] = -1;
        return val;
    }

    bool mouseButton(int button) {
        return Mouse::getInstance()[button] == GLFW_PRESS;
    }

    bool mouseButtonUp(int button) {
        bool val = Mouse::getInstance()[button] == GLFW_RELEASE;
        if (val) Mouse::getInstance()[button] = -1;
        return val;
    }

    double* mousePos() {
        static double positions[2];
        positions[0] = Mouse::getInstance().m_xPos;
        positions[1] = Mouse::getInstance().m_yPos;
        return positions;
    }

    double* mouseScroll() {
        static double scroll[2];
        scroll[0] = Mouse::getInstance().m_scrollX;
        scroll[1] = Mouse::getInstance().m_scrollY;
        return scroll;
    }

    double* mouseDelta() {
        static double delta[2];
        delta[0] = Mouse::getInstance().m_xPos - Mouse::getInstance().m_lastX;
        delta[1] = Mouse::getInstance().m_yPos - Mouse::getInstance().m_lastY;
        return delta;
    }

    bool mouseDragging() {
        return Mouse::getInstance().isDragging;
    }

    void resetScroll() {
        Mouse::getInstance().m_scrollX = 0;
        Mouse::getInstance().m_scrollY = 0;
    }

}

#endif //EVENTS_H
