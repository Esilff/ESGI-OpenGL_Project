//
// Created by Esilff on 05/04/2023.
//

#include "Entity.h"

Entity::Entity() {}

Entity::Entity(const Mesh &mesh, const Shader &shader) {
    m_mesh = mesh;
    m_shader = shader;
}

void Entity::update() {
    m_shader.bind();
    m_mesh.draw();
}