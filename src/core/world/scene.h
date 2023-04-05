//
// Created by Esilff on 05/04/2023.
//

#ifndef SCENE_H
#define SCENE_H


#include <vector>
#include "entity.h"

class Scene {
    std::vector<Entity> m_entities;


public:
    void update();
    void addEntity();
    void addEntity(const Entity& e);
};


#endif //SCENE_H
