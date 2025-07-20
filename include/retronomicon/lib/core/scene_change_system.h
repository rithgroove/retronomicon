#pragma once

#include "retronomicon/lib/core/system.h"
#include "retronomicon/lib/engine/game_engine.h"
#include "retronomicon/lib/core/scene_change_component.h"
#include <vector>

namespace retronomicon::lib::core::system {

    using retronomicon::lib::core::Entity;
    using retronomicon::lib::engine::GameEngine;
    using retronomicon::lib::core::component::SceneChangeComponent;

    class SceneChangeSystem : public System {
    public:
        SceneChangeSystem(GameEngine* engine)
            : m_engine(engine) {}

        void update(float deltaTime, std::vector<Entity*>& objects) override;

    private:
        GameEngine* m_engine;
    };

}
