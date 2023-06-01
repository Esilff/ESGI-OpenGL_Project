cmake_minimum_required(VERSION 3.2)
project(ESGI_OpenGL)

set(CMAKE_CXX_STANDARD 14)

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        find_package(OpenGL REQUIRED)
        set(PROJECT_NAME "${PROJECT_NAME}")
        configure_file(config.sh.in config.sh @ONLY)
endif()

add_executable(${PROJECT_NAME}
src/main.cpp src/core/rendering/mesh.h src/core/rendering/mesh.cpp src/core/rendering/shader.h src/core/rendering/shader.cpp src/core/rendering/texture.h src/core/rendering/texture.cpp
src/core/window.h src/core/window.cpp
src/core/world/Entity.cpp src/core/world/Entity.h src/core/world/scene.cpp src/core/world/scene.h src/core/util/glUtil.h src/core/system/Time.cpp src/core/system/Time.h
src/core/events/events.h src/core/events/eventCallbacks.h src/core/events/Keyboard.h src/core/events/Keyboard.cpp src/core/events/Mouse.cpp src/core/events/Mouse.h src/core/math/math.h src/core/math/math.cpp)

#adding GLEW directory to project

add_subdirectory(dependencies/glfw-3.3.8)

#setup GLAD

include_directories(dependencies/glad/include)
add_library(glad dependencies/glad/src/glad.c)

#setup stb-image lib

include_directories(dependencies/stb)
link_directories(dependencies/stb)

add_subdirectory(dependencies/jsoncpp)
get_target_property(JSON_INC_PATH jsoncpp_static INTERFACE_INCLUDE_DIRECTORIES)
include_directories(${JSON_INC_PATH})

#linking GLFW, OpenGL and GLAD

target_link_libraries(${PROJECT_NAME} glfw glad jsoncpp_static)


if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
else()
        target_link_libraries(${PROJECT_NAME} opengl32)
endif()
#set variables that could be used in cpp
add_compile_definitions(SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
add_compile_definitions(GL_DEBUG_FLAG=1)
