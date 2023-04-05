#include "mesh.h"

Mesh::Mesh() {
    m_vertices = {
        -0.5f,-0.5f,0.0f,1.0f,1.0f,0.0f,1.0f,
        0.5f,-0.5f,0.0f,0.0f,1.0f,1.0f,0.5f,
        0.0f,0.5f,0.0f,1.0f,0.0f,1.0f,0.0f
    };
    m_indices = {0,1,2};
    m_vertexFormat = {XYZ, RGBA};
    loadMesh();
}

Mesh::Mesh(const Mesh &mesh) : m_vertices(mesh.m_vertices), m_indices(mesh.m_indices), m_vertexFormat(mesh.m_vertexFormat) {
    loadMesh();
}

Mesh::Mesh(const std::vector<float> &vertices,const std::vector<unsigned int> &indices,const std::vector<VertexInfo> &format) :
    m_vertices(vertices), m_indices(indices), m_vertexFormat(format){
    loadMesh();
}

void Mesh::draw() {
    glBindVertexArray(m_vao);
    glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
}

void Mesh::loadMesh() {
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    glGenBuffers(1, &m_ebo);
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), static_cast<void*>(m_vertices.data()), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(int), static_cast<void*>(m_indices.data()), GL_STATIC_DRAW);
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
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

int Mesh::vertexInfoLength(VertexInfo vi) {
    if (vi == XY || vi == UV) return 2;
    if (vi == XYZ || vi == RGB) return 3;
    if (vi == RGBA) return 4;
    return 0;
}

Mesh::~Mesh() {
    /*glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);*/
}