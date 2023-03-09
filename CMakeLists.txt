cmake_minimum_required(VERSION 3.24)
project(ESGI_OpenGL_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(ESGI_OpenGL_Project
        main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(include/glfw-3.3.8)

include_directories(include/glew-2.1.0/include)
target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/include/glew-2.1.0/lib/Release/x64/glew32s.lib)




find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw glew32 opengl32)



