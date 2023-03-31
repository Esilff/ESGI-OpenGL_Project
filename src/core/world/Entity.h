//
// Created by Esilff on 23/03/2023.
//

#ifndef ESGI_OPENGL_ENTITY_H
#define ESGI_OPENGL_ENTITY_H


#include "../rendering/shader.h"
#include "../rendering/mesh.h"

class Entity {
    Mesh m_mesh;
    Shader m_shader;

public:
    Entity();
    void update();
};


#endif //ESGI_OPENGL_ENTITY_H
