#include "window.h"
#include "world/entity.h"
#include "world/scene.h"
#include "system/Time.h"
#include "events/events.h"



void Window::init() {
    setAppParams();
    if (!glfwInit()) {
        throw std::runtime_error("Unable to initialize GLFW");
    }
    m_window = glfwCreateWindow(m_width,m_height,m_name.c_str(), nullptr, nullptr);
    if (!m_window) {
        glfwTerminate();
        throw std::runtime_error("Unable to initialize the window");
    }
    glfwMakeContextCurrent(m_window);
    if(!gladLoadGL()) {
        throw std::runtime_error("Unable to initialize GLAD");
    }
    if (GL_DEBUG_FLAG) {
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(GLUtil::glDebugCallback, nullptr);
    }
    m_frameCap = 1.0/m_fps;
    glfwSwapInterval(1);//Activating vsync by default
    setCallbacks();
}

void Window::loop() {
    //Treating time values to check if fps is passing
    bool canRender = false;
    double frameTime = 0;
    double unprocessed = 1;
    double frames = 0;
    Scene s;
    s.addEntity();
    s.addEntity(Entity {
            Mesh {
                    {
                        1.0f,0.0f,0.0f,1.0f,0.0f,0.0f,1.0f,
                        1.0f,1.0f,0.0f,0.0f,1.0f,0.0f,1.0f,
                        0.0,1.0f,0.0f,0.0f,0.0f,1.0f,0.0f
                    },
                    {0,1,2}, {XYZ, RGBA}
            }, Shader()
    });
    while (!glfwWindowShouldClose(m_window)) {
        Time::update();
        frameTime += Time::dt();
        unprocessed += Time::dt();

        while(unprocessed > m_frameCap) {
            unprocessed -= m_frameCap;
            canRender = true;
        }
        if (canRender) {
            frames++;
            glClearColor(.1f,.1f,.1f,1.f);
            glClear(GL_COLOR_BUFFER_BIT);
            //s.update();
            if (Events::mouseDragging()) {
                std::cout << "Dragging" << std::endl;
            }
            glfwSwapBuffers(m_window);
            updateEvents();
            if (frameTime >= 1.0) {
                frameTime = 0;
                std::cout << "Fps : " << frames << std::endl;
                frames = 0;
            }
        }
    }
}

void Window::setCallbacks() {
    glfwSetKeyCallback(m_window, keyCallback);
    glfwSetCursorPosCallback(m_window,mousePosCallback);
    glfwSetMouseButtonCallback(m_window, mouseButtonCallback);
    glfwSetScrollCallback(m_window, mouseScrollCallback);
}

void Window::updateEvents() {
    Events::resetScroll();
    glfwPollEvents();
}

void Window::setAppParams() {
    Json::Value appInfo = readAppInfo();
    m_name = appInfo["name"].asString();
    m_width = appInfo["defaultWidth"].asInt();
    m_height = appInfo["defaultHeight"].asInt();
}

Json::Value Window::readAppInfo() {
    std::ifstream file(std::string(SOURCE_DIR) + "/data/app.config.json");
    if (!file.is_open()) {
        throw std::runtime_error("No app config found to initialize window. (No app.config.json found in data)");
    }
    std::string line, jsonContent;
    while(std::getline(file, line)) jsonContent += line;
    file.close();
    Json::Value root;
    Json::Reader reader;
    bool success = reader.parse(jsonContent, root, false);
    if (!success) {
        throw std::runtime_error("Unable to parse app.config.json check the file again for errors");
    }
    return root;
}
