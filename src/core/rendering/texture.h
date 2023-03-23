#ifndef TEXTURE_H
#define TEXTURE_H
#include <iostream>
#include <string>
#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

class Texture {
    unsigned int m_texture;
    int m_width, m_height, m_channels;
    unsigned char* m_data;
    std::string m_path;

public:
    Texture(const std::string &path);
    void bind(int texId = 0);
};

#endif