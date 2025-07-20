#pragma once

#include <string>
#include <memory>
#include <vector>
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

        Entity* createGameObject(const string& name);
        void removeGameObject(Entity* object);
        void addSystem(System* system);

    private:
        string m_name;
        vector<Entity*> m_gameObjects;
        vector<System*> m_systems;
    };
}