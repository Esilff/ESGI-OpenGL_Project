cmake_minimum_required(VERSION 3.2)
project(ESGI_OpenGL)

set(CMAKE_CXX_STANDARD 14)

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        find_package(OpenGL REQUIRED)
        set(PROJECT_NAME "${PROJECT_NAME}")
        configure_file(config.sh.in config.sh @ONLY)

endif()

add_executable(${PROJECT_NAME}
        src/main.cpp src/core/rendering/mesh.h src/core/rendering/mesh.cpp)

#adding GLEW directory to project

add_subdirectory(dependencies/glfw-3.3.8)

#setup GLAD

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glad/include)
add_library(glad dependencies/glad/src/glad.c)

#linking GLFW, OpenGL and GLAD

target_link_libraries(${PROJECT_NAME} glfw glad)

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
else()
        target_link_libraries(${PROJECT_NAME} opengl32)
endif()
#set variables that could be used in cpp
add_compile_definitions(SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
