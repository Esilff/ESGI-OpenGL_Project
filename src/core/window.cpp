#include "window.h"

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
}

void Window::loop() {
    m_scene.addEntity();
   /* Shader shader;
    Mesh mesh;*/
    while (!glfwWindowShouldClose(m_window)) {
        glClearColor(.1f,.1f,.1f,1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        m_scene.update();
        /*shader.bind();
        mesh.draw();*/
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
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
