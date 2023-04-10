//
// Created by Esilff on 10/04/2023.
//

#ifndef MOUSE_H
#define MOUSE_H
#define MOUSE_INPUT_SUPPORT 3


class Mouse {
    //Define singleton structure
    Mouse();
    Mouse(const Mouse& mouse) = delete;
    void operator=(const Mouse& mouse) = delete;

public:
    static Mouse& getInstance() {
        static Mouse instance;
        return instance;
    }

    double m_scrollX;
    double m_scrollY;
    double m_xPos;
    double m_yPos;
    double m_lastX;
    double m_lastY;

    int mouseKeys[MOUSE_INPUT_SUPPORT];
    bool isDragging;

    int& operator[](int button);
};


#endif //ESGI_OPENGL_MOUSE_H
