#include "scene.h"

void Scene::load() {
    m_isLoaded = false;
}

void Scene::update() {
    for (Entity item: m_entities) {
        item.update();
    }
}

void Scene::addEntity() {
    m_entities.emplace_back();
}