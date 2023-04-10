//
// Created by Esilff on 10/04/2023.
//

#include "Mouse.h"

Mouse::Mouse() {
    m_scrollX = 0;
    m_scrollY = 0;
    m_lastX = 0;
    m_lastY = 0;
    m_xPos = 0;
    m_yPos = 0;
    for (int i = 0; i < MOUSE_INPUT_SUPPORT; i++) mouseKeys[i] = -1;
    isDragging = false;
}

int &Mouse::operator[](int button) {
    return mouseKeys[button];
}