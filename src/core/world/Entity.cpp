#include "Entity.h"

Entity::Entity() {
    m_mesh = Mesh();
}

void Entity::update() {
    m_shader.bind();
    m_mesh.draw();
}