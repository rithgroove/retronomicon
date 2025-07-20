#pragma once

#include "retronomicon/lib/core/system.h"
#include "retronomicon/lib/core/game_object.h"
#include "retronomicon/lib/core/game_engine.h"
#include "retronomicon/lib/core/component/scene_change_component.h"
#include <vector>

namespace retronomicon::lib::core::system {

    using retronomicon::lib::core::GameObject;
    using retronomicon::lib::core::GameEngine;
    using retronomicon::lib::core::component::SceneChangeComponent;

    class SceneChangeSystem : public System {
    public:
        SceneChangeSystem(GameEngine* engine)
            : m_engine(engine) {}

        void update(float deltaTime, std::vector<GameObject*>& objects) override;

    private:
        GameEngine* m_engine;
    };

}
