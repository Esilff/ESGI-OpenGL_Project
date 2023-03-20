#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include "core/rendering/shader.h"
#include "core/rendering/mesh.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

float vertices[] = {
        -0.5f, -0.5f, 0.0f,0.8,0.2,0.25,
        0.5f,-0.5f,0.0f,0.2,0.4,0.4,
        0.0f,0.5f,0.0f,0.5,0.4,0.8
};


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


    Mesh mesh = Mesh({
         0.5f,-0.5f,0.0f,1.0f,1.0f,
        -0.5f,-0.5f,0.0f,1.0f,0.0f,
         -0.5f,0.5f,0.0f,0.0f,0.0f,
         0.5f,0.5f,0.0f,0.0f,1.0f
    },
{
        0,1,2,
        3,0,2
    }
    ,{XYZ, XY});

    Shader shader = Shader("src/shaders/basic.glsl");

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, channels;
    std::string filePath = SOURCE_DIR;
    filePath+= "/assets/ats_scaled.png";
    unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &channels,0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    //Loading vertices
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    while(!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glClearColor(0.1,0.1,0.1,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        shader.bind();
        mesh.draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
