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
        virtual ~Scene();

        virtual void init();
        virtual void update(float dt);
        virtual void render();
        virtual void shutdown();
        virtual void reset();

        bool isInitialized(){return m_isInitialized;}
        bool requiresReset(){return m_requiresReset;}
        bool isActive(){return m_isActive;}
        void setInitialized(bool value){m_isInitialized = value;}
        void setRequiresReset(bool value){m_requiresReset=value;}
        void setActive(bool value){m_isActive = value;}

        string getName() const;

        Entity* createGameObject(const string& name);
        void removeGameObject(Entity* object);
        void addSystem(System* system);

    private:
        string m_name;
        bool m_isInitialized;
        bool m_requiresReset;
        bool m_isActive;
        vector<Entity*> m_gameObjects;
        vector<System*> m_systems;
    };
}