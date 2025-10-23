#pragma once

#include "system.h"
#include "retronomicon/entity/entity.h"
#include "retronomicon/component/scene_change_component.h"
#include "retronomicon/engine/game_engine.h"

namespace retronomicon::system {
    using retronomicon::entity::Entity;
    using retronomicon::component::SceneChangeComponent;
    using retronomicon::engine::GameEngine;
    class SceneChangeSystem : public System {
    public:
        explicit SceneChangeSystem(GameEngine* engine)
            : m_engine(engine) {}

        void update(float dt, std::weak_ptr<Entity> entity) override;

    private:
        GameEngine* m_engine = nullptr; // non-owning pointer to the engine controlling scenes
    };

} // namespace retronomicon::scene
