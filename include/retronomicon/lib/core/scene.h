#pragma once

#include <string>
#include <memory>
#include <vector>
#include "game_object.h"
#include "retronomicon/lib/core/entity.h"
#include "system.h"

using namespace std;
namespace retronomicon::lib::core {

    class Scene : public Entity {
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
        void addSystem(System* system);

    private:
        string m_name;
        vector<GameObject*> m_gameObjects;
        vector<System*> m_systems;
    };
}