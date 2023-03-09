cmake_minimum_required(VERSION 3.24)
project(ESGI_OpenGL_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(ESGI_OpenGL_Project
        src/main.cpp)

#adding GLEW directory to project

add_subdirectory(dependencies/glfw-3.3.8)

#setup GLAD

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glad/include)
add_library(glad dependencies/glad/src/glad.c)

#linking GLFW, OpenGL and GLAD

target_link_libraries(${PROJECT_NAME} glfw opengl32 glad)