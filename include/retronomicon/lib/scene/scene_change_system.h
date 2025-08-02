#pragma once

#include "retronomicon/lib/core/system.h"
#include "retronomicon/lib/engine/game_engine.h"
#include "retronomicon/lib/scene/scene_change_component.h"
#include <vector>

namespace retronomicon::lib::scene {

    using retronomicon::lib::core::Entity;
    using retronomicon::lib::engine::GameEngine;
    using retronomicon::lib::scene::SceneChangeComponent;

    class SceneChangeSystem : public retronomicon::lib::core::System {
    public:
        SceneChangeSystem(GameEngine* engine)
            : m_engine(engine) {}

        void update(float deltaTime, Entity* objects) override;

    private:
        GameEngine* m_engine;
    };

}
