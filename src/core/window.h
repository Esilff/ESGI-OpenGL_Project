#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <GLFW/glfw3.h>


class Window {

    std::string m_name;
    GLFWwindow * m_window;

    Window() {
        init();
        loop();
    }
    Window(const Window&);
    Window& operator= (const Window& other);
    void init();
    void loop();

public:

  

    static Window getInstance() {
        static Window instance;
        return instance;
    }
};

#endif