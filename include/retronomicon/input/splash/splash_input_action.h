#pragma once

#include "retronomicon/input/input_action.h"
#include "retronomicon/entity/entity.h"
#include "retronomicon/component/scene_change_component.h"

namespace retronomicon::input::splash {
    using namespace retronomicon::input;
    using retronomicon::entity::Entity;
    /**
     * @brief Action used in the Splash Screen.
     * When the "Confirm" action is pressed, we trigger SceneChangeComponent.
     */
    class SplashInputAction : public InputAction {
    public:
        explicit SplashInputAction()
            : m_targetScene() {}

        void execute(std::weak_ptr<Entity> entity,
                     const InputState& state) override;

    private:
        std::string m_targetScene;
    };

} // namespace retronomicon::input
