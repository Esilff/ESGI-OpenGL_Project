//
// Created by Esilff on 05/04/2023.
//

#include "scene.h"

void Scene::update() {
    for (int i = 0; i < m_entities.size(); i++) m_entities[i].update();
}

void Scene::addEntity() {
    m_entities.emplace_back();
}

void Scene::addEntity(const Entity &e) {
    m_entities.push_back(e);
}