#include "Entity.h"

Entity::Entity() {
    mesh = Mesh();
}

void Entity::update() {
    shader.bind();
    mesh.draw();
}