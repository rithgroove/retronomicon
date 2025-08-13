// InputComponent.hpp
#pragma once

#include "input_state.h"   // your global/hardware state wrapper
#include "retronomicon/lib/core/component.h"

namespace retronomicon::lib::input {

    /**
     * @brief Abstract base for all input-intent components.
     * - Defines per-frame lifecycle for input handling.
     * - Subclasses translate hardware input into gameplay actions.
     */
    class InputComponent : public retronomicon::lib::core::Component {
    public:
        virtual ~InputComponent() = default;

        /**
         * @brief Called at the start of each frame to reset transient flags.
         */
        virtual void beginFrame() = 0;

        /**
         * @brief Feed hardware-level input for this frame.
         * @param state Current hardware input state.
         * @param dt Delta time since last frame.
         */
        virtual void updateFromState(const InputState& state, float dt) = 0;
    };

} // namespace retronomicon::lib::input
