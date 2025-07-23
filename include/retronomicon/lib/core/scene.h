#pragma once

#include <string>
#include <memory>
#include <vector>
#include "retronomicon/lib/core/entity.h"
#include "system.h"

namespace retronomicon::lib::core {

    class Scene : public Entity {
    public:
        explicit Scene(const std::string& name);
        virtual ~Scene();

        // Lifecycle
        virtual void init();
        virtual void update(float dt);
        virtual void render();
        virtual void shutdown();
        virtual void reset();

        // GameObject & System management
        Entity* createGameObject(const std::string& name);
        void removeGameObject(Entity* object);
        void addSystem(System* system);

        // State accessors (inlined)
        inline const std::string& getName() const { return m_name; }
        inline bool isInitialized() const { return m_isInitialized; }
        inline bool isActive() const { return m_isActive; }
        inline bool requiresReset() const { return m_requiresReset; }A

        inline void setInitialized(bool value) { m_isInitialized = value; }
        inline void setActive(bool value) { m_isActive = value; }
        inline void setRequiresReset(bool value) { m_requiresReset = value; }

    protected:
        std::string m_name;

        std::vector<Entity*> m_gameObjects;
        std::vector<System*> m_systems;

        bool m_isInitialized = false;
        bool m_isActive = false;
        bool m_requiresReset = false;
    };

}
