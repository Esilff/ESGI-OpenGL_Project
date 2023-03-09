cmake_minimum_required(VERSION 3.24)
project(ESGI_OpenGL_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(ESGI_OpenGL_Project
        src/main.cpp)

add_subdirectory(dependencies/glfw-3.3.8)
include_directories(dependencies/glew-2.1.0/include)

target_link_libraries(${PROJECT_NAME} glfw opengl32)
target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glew-2.1.0/lib/Release/x64/glew32s.lib)