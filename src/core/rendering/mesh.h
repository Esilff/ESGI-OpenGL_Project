#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glad/glad.h>


class Mesh {
    std::vector<float> m_vertices;
    unsigned int m_vbo;

public:
    Mesh();
    void draw();

};

#endif