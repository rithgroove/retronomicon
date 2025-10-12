#pragma once
#include <retronomicon/core/ecs/system.h>
#include <retronomicon/core/ecs/entity.h>
#include "scene_change_component.h"
#include <retronomicon/engine/game_engine.h> 

namespace retronomicon::scene {

    using retronomicon::engine::GameEngine;
    class SceneChangeSystem : public core::ecs::System {
    public:
        explicit SceneChangeSystem(GameEngine* engine)
            : m_engine(engine) {}

        void update(float dt, std::weak_ptr<core::ecs::Entity> entity) override;

    private:
        GameEngine* m_engine = nullptr; // non-owning pointer to the engine controlling scenes
    };

} // namespace retronomicon::scene
