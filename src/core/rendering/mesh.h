#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glad/glad.h>
#include <iostream>

enum VertexInfo {
    XY,
    XYZ,
    RGB,
    RGBA
};

class Mesh {
    std::vector<float> m_vertices;
    std::vector<VertexInfo> m_vertexFormat;
    int m_drawCount = 0;
    int m_vertexSize = 0;
    unsigned int m_vbo;
    unsigned int m_vao;

    int vertexInfoLength(VertexInfo vi);

public:
    Mesh();
    Mesh(std::vector<float> vertices, std::vector<VertexInfo> format);
    ~Mesh();
    void draw();

};

#endif