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
}

#endif //EVENTS_H
