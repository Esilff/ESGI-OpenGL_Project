#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include "util/FileParser.cpp"
#include <filesystem>

float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f,-0.5f,0.0f,
        0.0f,0.5f,0.0f
};



unsigned int vbo;


int main() {
    std::array<std::string, 2> shaderSource = fparse::parseShader("src/shaders/basicShader.glsl");
    std::cout << shaderSource[0] << std::endl;
    std::cout << shaderSource[1] << std::endl;
    /*GLFWwindow * window;
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    window = glfwCreateWindow(640,480, "ESGI-OpenGL_Project_dev", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to initialize the window");
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGL()) {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }*/
    return 0;
}
