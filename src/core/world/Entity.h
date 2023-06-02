//
// Created by Esilff on 05/04/2023.
//

#ifndef ENTITY_H
#define ENTITY_H

#include "../rendering/mesh.h"
#include "../rendering/shader.h"
#include "transform.h"
#include "Camera.h"

class Entity{
    Transform transform;
    Mesh m_mesh;
    Shader m_shader;
public:
    Entity();
    Entity(const Mesh &mesh, const Shader &shader);
    void render(const Camera& camera);

    void Move(const Vector& vector);
    void SetPosition(const Vector& vector);
    void Rotate(const Vector& rotate);
};


#endif //ENTITY_H
