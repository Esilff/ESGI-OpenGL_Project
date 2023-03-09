cmake_minimum_required(VERSION 3.24)
project(ESGI_OpenGL_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(ESGI_OpenGL_Project
        src/main.cpp)

add_subdirectory(dependencies/glfw-3.3.8)


target_link_libraries(${PROJECT_NAME} glfw opengl32)