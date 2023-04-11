#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <json/json.h>
#include <fstream>
#include <stdexcept>
#include "util/glUtil.h"
#include "events/eventCallbacks.h"

#include "system/Time.h"

class Window {

    std::string m_name;
    int m_width;
    int m_height;
    GLFWwindow * m_window;
    GLFWmonitor * m_primaryMonitor;
    GLFWvidmode * m_vidMode;
    bool m_isFullscreen;

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
    void setCallbacks();
    void updateEvents();
    void checkWindowEvents();

public:

    static Window getInstance() {
        static Window instance;
        return instance;
    }

    GLFWwindow * window();
};

#endif