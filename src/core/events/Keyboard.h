//
// Created by Esilff on 06/04/2023.
//

#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <GLFW/glfw3.h>

class Keyboard {
    int m_keys[350];

    Keyboard() {
        for (int i = 0; i < 350; i++) m_keys[i] = -1;
    }

    Keyboard(const Keyboard& keyboard) {};

public:


    static Keyboard& getInstance() {
        static Keyboard instance;
        return instance;
    }

    int& operator[](int keycode);
};


#endif //KEYBOARD_H
