#pragma once

#include "retronomicon/input/input_action.h"
#include "retronomicon/entity/entity.h"
#include "retronomicon/component/scene_change_component.h"

namespace retronomicon::input::splash {

    using namespace retronomicon::input;
    using retronomicon::entity::Entity;

    /**
     * @brief Input action used on the splash screen to advance to the next scene.
     *
     * This action is typically bound to a "Confirm" input (e.g. ENTER, A button, tap).
     *
     * Behavior:
     *  - When executed, it looks for a `SceneChangeComponent` on the target entity.
     *  - If found, it sets the next-scene name and triggers the transition.
     *  - The exact scene to load is configured internally or through external game logic.
     *
     * Used during early boot to transition from:
     *  **Splash → Title Menu**,  
     *  **Splash → Intro Cutscene**, etc.
     */
    class SplashInputAction : public InputAction {
    public:
        /**
         * @brief Construct the action with no initial target scene.
         *
         * The target scene may be assigned inside the implementation of `execute()`,
         * or injected through other initialization logic.
         */
        explicit SplashInputAction()
            : m_targetScene() {}

        /**
         * @brief Execute the action when its input binding is fired.
         *
         * @param entity Weak reference to the entity receiving this action.
         *               Typically the splash screen controller entity.
         * @param state  The input state at the moment of execution.
         *
         * Expected flow inside implementation:
         *  - Lock the entity.
         *  - Fetch its `SceneChangeComponent`.
         *  - Set `m_targetScene` into that component.
         *  - Call `trigger()` on the component.
         */
        void execute(std::weak_ptr<Entity> entity,
                     std::shared_ptr<InputState> state) override;

    private:
        std::string m_targetScene; ///< Scene to transition to when action fires.
    };

} // namespace retronomicon::input::splash
