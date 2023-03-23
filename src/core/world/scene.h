#ifndef ESGI_OPENGL_SCENE_H
#define ESGI_OPENGL_SCENE_H
#include "Entity.h"
#include <vector>

class Scene {
    bool m_isLoaded;
    std::vector<Entity> m_entities;

public:
    void load();
    void update();

    void addEntity();
};


#endif //ESGI_OPENGL_SCENE_H
