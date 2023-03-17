#include "mesh.h"

Mesh::Mesh() {
    m_vertices = {
        -0.5f,-0.5f,0.0f,1.0f,1.0f,0.0f,
        0.5f,-0.5f,0.0f,0.0f,1.0f,1.0f,
        0.0f,0.5f,0.0f,1.0f,0.0f,1.0f
    };

    m_vertexFormat = {XYZ,RGB};
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), static_cast<void*>(m_vertices.data()), GL_STATIC_DRAW);
    for (int i = 0; i < m_vertexFormat.size(); i++) {
        m_vertexSize += vertexInfoLength(m_vertexFormat[i]);
    }
    m_drawCount = m_vertices.size() / m_vertexSize;
    std::cout << "VertexSize : " << m_vertexSize << std::endl;
    std::cout << "Draw count : " << m_drawCount << std::endl;
    int offset = 0;
    for (int i = 0; i < m_vertexFormat.size(); i++) {
        int vLength = vertexInfoLength(m_vertexFormat[i]);
        std::cout << "Vertices[" << i << "] : vLength, " << vLength << " : offset, " << offset << std::endl;
        glVertexAttribPointer(i,vLength, GL_FLOAT, GL_FALSE, m_vertexSize * sizeof(float),(void*) (offset * sizeof(float)));
        glEnableVertexAttribArray(i);
        offset += vLength;
    }
}

void Mesh::draw() {
    glDrawArrays(GL_TRIANGLES,0,3);
}

int Mesh::vertexInfoLength(VertexInfo vi) {
    if (vi == XY) return 2;
    if (vi == XYZ || vi == RGB) return 3;
    return 0;
}

Mesh::~Mesh() {
    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);
}