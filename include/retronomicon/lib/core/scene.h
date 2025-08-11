#pragma once

#include <string>
#include <memory>
#include <vector>
#include "retronomicon/lib/core/entity.h"
#include "system.h"

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

        bool isInitialized() const { return m_isInitialized; }
        bool requiresReset() const { return m_requiresReset; }
        bool isActive() const { return m_isActive; }

        void setInitialized(bool value) { m_isInitialized = value; }
        void setRequiresReset(bool value) { m_requiresReset = value; }
        void setActive(bool value) { m_isActive = value; }
        void addSystem(std::unique_ptr<System> system);

    protected:
        bool m_isInitialized = false;
        bool m_requiresReset = false;
        bool m_isActive = false;

        std::vector<std::unique_ptr<System>> m_systems;
    };

}
