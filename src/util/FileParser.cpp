#include <string>
#include <array>
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace project {
    enum ShaderType {
        VERTEX,
        FRAGMENT
    };
}

namespace fparse {
    std::array<std::string, 2> parseShader(const std::string &shaderName) {
        std::array<std::string, 2> shaderSources;
        std::ifstream vertexSource(std::string(SOURCE_DIR) + "/" + shaderName + ".vert");
        if (!vertexSource.is_open()) {
            std::cout << "No vertex shader found for : " << shaderName << std::endl;
        }
        std::ifstream fragmentSource(std::string(SOURCE_DIR) + "/" + shaderName + ".frag");
        if (!fragmentSource.is_open()) {
            std::cout << "No fragment shader found for : " << shaderName << std::endl;
        }
        std::string vertContent((std::istreambuf_iterator<char>(vertexSource)), std::istreambuf_iterator<char>());
        std::string fragContent((std::istreambuf_iterator<char>(fragmentSource)), std::istreambuf_iterator<char>());
        shaderSources[project::VERTEX] = vertContent;
        shaderSources[project::FRAGMENT] = fragContent;
        return shaderSources;
    }
}
