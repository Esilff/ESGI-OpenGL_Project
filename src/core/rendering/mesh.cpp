#include "mesh.h"

Mesh::Mesh() {
    m_vertices = {
        -0.5f,-0.5f,0.0f,
        0.5f,-0.5f,0.0f,
        0.0f,0.5f,0.0f
    };
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), static_cast<void*>(m_vertices.data()), GL_STATIC_DRAW);
    
}

void Mesh::draw() {
    glDrawArrays(GL_TRIANGLES,0,3);
}