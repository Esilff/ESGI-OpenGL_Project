#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include "util/FileParser.cpp"

float vertices[] = {
        -0.5f, -0.5f, 0.0f,0.8,0.2,0.25,
        0.5f,-0.5f,0.0f,0.2,0.4,0.4,
        0.0f,0.5f,0.0f,0.5,0.4,0.8
};



unsigned int vbo;


int main() {
    GLFWwindow * window;
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
    //Loading vertices
    std::array<std::string, 2> shaderSource = fparse::parseShader("src/shaders/basic");
    const char* vs = shaderSource[0].c_str();
    const char* fs = shaderSource[1].c_str();
    glGenBuffers(1, &vbo);
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    //compiling vertex shader
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vs, nullptr);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cout << "Could not compile the vertexShader :\n" << infoLog << std::endl;
    }
    //compiling fragmentShader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fs, nullptr);
    glCompileShader(fragmentShader);
    int fragSuccess;
    char fragInfoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragSuccess);
    if (!fragSuccess) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, fragInfoLog);
        std:: cout << "Could not compile the fragmentShader :\n" << fragInfoLog << std::endl;
    }
    //create shader program
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glVertexAttribPointer(glGetAttribLocation(shaderProgram, "aPos"), 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) 0);
    glVertexAttribPointer(glGetAttribLocation(shaderProgram, "aCol"), 3,GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(glGetAttribLocation(shaderProgram, "aPos"));
    glEnableVertexAttribArray(glGetAttribLocation(shaderProgram, "aCol"));

    while(!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glClearColor(0.1,0.1,0.1,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
