#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <json/json.h>
#include <fstream>
#include <stdexcept>
#include "util/glUtil.h"


class Window {

    std::string m_name;
    int m_width;
    int m_height;
    GLFWwindow * m_window;

    int m_fps = 60;
    double m_frameCap;

    Window() {
        init();
        loop();
    }
    Window(const Window&) {};

    void init();
    void loop();
    Json::Value readAppInfo();
    void setAppParams();

public:

    static Window getInstance() {
        static Window instance;
        return instance;
    }

    GLFWwindow * window();
};

#endif