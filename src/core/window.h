#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <json/json.h>
#include <fstream>
#include <stdexcept>


class Window {

    std::string m_name;
    int m_width;
    int m_height;
    GLFWwindow * m_window;

    Window() {
        init();
        loop();
    }
    Window(const Window&) {};
    Window& operator= (const Window& other) {};
    void init();
    void loop();
    Json::Value readAppInfo();
    void setAppParams();

public:

  

    static Window getInstance() {
        static Window instance;
        return instance;
    }
};

#endif