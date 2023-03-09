#include <string>
#include <array>
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace fparse {
    std::array<std::string, 2> parseShader(const std::string &path) {
        int type = -1;
        std::array<std::string, 2> shaderSources;
        std::ifstream file(std::string(SOURCE_DIR) + "/" + path);
        if (!file.is_open()) {
            throw std::invalid_argument("No file found for the following path : " + path);
        }
        std::string line;
        while (std::getline(file, line)) {
            if (line == "#pragma vertex" || line == "#pragma fragment") {
                type++;
            }
            shaderSources[type].append(line);
        }
        return shaderSources;
    }
}
