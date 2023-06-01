//
// Created by Esilff on 05/04/2023.
//

#include "Entity.h"

Entity::Entity() {}

Entity::Entity(const Mesh &mesh, const Shader &shader) {
    m_mesh = mesh;
    m_shader = shader;
}

void Entity::render(const Camera& camera) {
    m_shader.bind();
    m_shader.setUniform("projectionMatrix", camera.getProjectionMatrix());
    m_shader.setUniform("viewMatrix", camera.getViewMatrix());
    m_shader.setUniform("modelMatrix", transform.getModelMatrix());
    m_mesh.draw();
}

void Entity::Move(const Vector &vector) {
    transform.position += vector;
}

void Entity::SetPosition(const Vector &vector) {
    transform.position = vector;
}

void Entity::Rotate(const Vector &rotate) {
    transform.rotation *= Quaternion().euler(rotate.x, rotate.y, rotate.z);
}

