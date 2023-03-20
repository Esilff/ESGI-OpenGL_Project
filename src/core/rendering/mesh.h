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
    std::vector<unsigned int> m_indices;
    std::vector<VertexInfo> m_vertexFormat;
    int m_drawCount = 0;
    int m_vertexSize = 0;
    unsigned int m_vbo;
    unsigned int m_vao;
    unsigned int m_ebo;


    void loadMesh();
    int vertexInfoLength(VertexInfo vi);

public:
    Mesh();
    Mesh(std::vector<float> vertices, std::vector<unsigned int> indices, std::vector<VertexInfo> format);
    ~Mesh();
    void draw();

};

#endif