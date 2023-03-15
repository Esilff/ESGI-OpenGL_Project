#include "mesh.h"

Mesh::Mesh() {
    m_vertices = {
        -0.5f,-0.5f,0.0f,
        0.5f,-0.5f,0.0f,
        0.0f,-0.5f,0.0f
    };
    glGenBuffers(1, &m_vbo);
    
}

void Mesh::draw() {

}