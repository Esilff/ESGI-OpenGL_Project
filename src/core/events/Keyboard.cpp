//
// Created by Esilff on 06/04/2023.
//

#include "Keyboard.h"

int &Keyboard::operator[](int keycode)  {
    return m_keys[keycode];
}