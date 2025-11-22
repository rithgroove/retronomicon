#pragma once

#include <memory>
#include <string>
#include "retronomicon/entity/entity.h"
#include "retronomicon/input/input_state.h"

namespace retronomicon::input {
    using retronomicon::entity::Entity;
    /**
     * @brief Base class for all input-driven actions.
     *
     * Actions are triggered by InputSystem when a mapped input event occurs.
     * Extend this class in your game code (e.g., JumpAction, FireAction).
     */
    class InputAction {
    public:
        virtual ~InputAction() = default;

        /**
         * @brief Called when the action is triggered for an entity.
         *
         * @param entity The ECS entity performing the action.
         * @param state  The current InputState (pressed, held, axis data).
         */
        virtual void execute(std::weak_ptr<Entity> entity,
                             std::shared_ptr<InputState> state) = 0;
    };

} // namespace retronomicon::input
