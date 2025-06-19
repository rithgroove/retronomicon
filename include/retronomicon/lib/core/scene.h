#pragma once

#include <string>
#include <memory>
#include <vector>
#include "game_object.h"

namespace retronomicon::lib::core {

    class Scene {
    public:
        Scene(const std::string& name);
        ~Scene();

        void init();
        void update(float dt);
        void render();
        void shutdown();

        std::string getName() const;

        GameObject* createGameObject(const string& name);
        void removeGameObject(GameObject* object);


    private:
        std::string m_name;
        std::vector<GameObject*> m_gameObjects;
    };
}