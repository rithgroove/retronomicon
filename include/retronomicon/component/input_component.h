// InputComponent.hpp
#pragma once

#include <memory>
#include "input_state.h"
#include "retronomicon/component/component.h"

namespace retronomicon::component {

    /**
     * @brief Base class for input-aware ECS components.
     * - Stores pointer to global InputState (from GameEngine).
     * - Subclasses read from the state during update().
     */
    class InputComponent : public retronomicon::component::Component {
    public:
        explicit InputComponent(std::shared_ptr<InputState> state)
            : m_inputState(std::move(state)) {}

        virtual ~InputComponent() = default;

        /**
         * @brief Subclasses implement how input affects the entity.
         */
        void update(float dt) override = 0;

    protected:
        std::shared_ptr<InputState> m_inputState; ///< Shared global state
    };

} // namespace retronomicon::lib::input
