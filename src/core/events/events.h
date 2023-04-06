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
        return Keyboard::getInstance()[keycode] == GLFW_REPEAT;
    }

    bool getKeyDown(int keycode) {
        return Keyboard::getInstance()[keycode] == GLFW_PRESS;
    }

    bool getKeyUp(int keycode) {
        return Keyboard::getInstance()[keycode] == GLFW_RELEASE;
    }
}

#endif //EVENTS_H
