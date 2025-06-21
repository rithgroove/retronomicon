#pragma once

#include <string>
#include <memory>
#include <vector>
#include "game_object.h"
#include "retronomicon/lib/core/system/system.h"

using namespace std;
using namespace retronomicon::lib::core::system;
namespace retronomicon::lib::core {

    class Scene {
    public:
        Scene(const std::string& name);
        ~Scene();

        void init();
        void update(float dt);
        void render();
        void shutdown();

        string getName() const;

        GameObject* createGameObject(const string& name);
        void removeGameObject(GameObject* object);


    private:
        string m_name;
        vector<GameObject*> m_gameObjects;
        vector<System*> m_systems;
    };
}