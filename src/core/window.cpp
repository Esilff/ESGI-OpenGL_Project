#include "window.h"
#include "world/Entity.h"
#include "world/scene.h"
#include "events/events.h"
#include <cmath>

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
    m_primaryMonitor = glfwGetPrimaryMonitor();
    if (m_isFullscreen) {
        const GLFWvidmode * mode = glfwGetVideoMode(m_primaryMonitor);
        glfwSetWindowMonitor(m_window,m_primaryMonitor,0,0,mode->width, mode->height, mode->refreshRate);
        glViewport(0,0,mode->width, mode->height);
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
    //s.addEntity();
    Shader shader;

    s.addEntity(Entity {
            Mesh {
                    {
                        1.0f,0.0f,0.0f,1.0f,0.0f,0.0f,1.0f,
                        1.0f,1.0f,0.0f,0.0f,1.0f,0.0f,1.0f,
                        0.0,1.0f,0.0f,0.0f,0.0f,1.0f,0.0f
                    },
                    {0,1,2}, {XYZ, RGBA}
            }, shader
    });
    double timeElapsed = 0;
    while (!glfwWindowShouldClose(m_window)) {
        Time::update();
        frameTime += Time::dt();
        unprocessed += Time::dt();
        timeElapsed+= Time::dt();
        while(unprocessed > m_frameCap) {
            unprocessed -= m_frameCap;
            canRender = true;
        }
        if (canRender) {
            frames++;
            glClearColor(.1f,.1f,.1f,1.f);
            glClear(GL_COLOR_BUFFER_BIT);
            s.update();
            shader.setUniform("u_Color", Vector((float) cos(timeElapsed), (float ) cos(timeElapsed), 0));
            glfwSwapBuffers(m_window);
            checkWindowEvents();
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
    glfwSetFramebufferSizeCallback(m_window, windowFrameBufferSizeCallback);
}

void Window::updateEvents() {
    Events::resetScroll();
    glfwPollEvents();
}

void Window::checkWindowEvents() {
    if (Events::getKeyDown(GLFW_KEY_F11)) {
        const GLFWvidmode* mode = glfwGetVideoMode(m_primaryMonitor);
        if (!m_isFullscreen) {
            glfwSetWindowMonitor(m_window, m_primaryMonitor,0,0,
                                 mode->width, mode->height, GLFW_DONT_CARE);
            glViewport(0,0,mode->width, mode->height);
            m_isFullscreen = !m_isFullscreen;
            return;
        }
        glfwSetWindowMonitor(m_window, NULL, 40,40,800,600,GLFW_DONT_CARE);
        glViewport(0,0,800,600);
        m_isFullscreen = !m_isFullscreen;
    }
}

void Window::setAppParams() {
    Json::Value appInfo = readAppInfo();
    m_name = appInfo["name"].asString();
    m_width = appInfo["defaultWidth"].asInt();
    m_height = appInfo["defaultHeight"].asInt();
    m_isFullscreen = appInfo["fullscreenStart"].asBool();
}

Json::Value Window::readAppInfo() {
    std::ifstream file(std::string(SOURCE_DIR) + "/settings/config.json");
    if (!file.is_open()) {
        throw std::runtime_error("No app config found to initialize window. (No config.json found in data)");
    }
    std::string line, jsonContent;
    while(std::getline(file, line)) jsonContent += line;
    file.close();
    Json::Value root;
    Json::Reader reader;
    bool success = reader.parse(jsonContent, root, false);
    if (!success) {
        throw std::runtime_error("Unable to parse config.json check the file again for errors");
    }
    return root;
}
