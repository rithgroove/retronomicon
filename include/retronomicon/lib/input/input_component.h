// InputComponent.hpp
#pragma once

#include "input_state.h"   //  your global/hardware state wrapper
#include "retronomicon/lib/core/component.h"

/**
 * Abstract base for all input‑intent components.
 *  - Holds no concrete data.
 *  - Defines the per‑frame life‑cycle contract.
 */
namespace retronomicon::lib::input{
    class InputComponent : public Component {
        public:
            virtual ~InputComponent() = default;

            /** Called once at frame start (reset transient flags). */
            virtual void beginFrame() = 0;

            /** Feed hardware‑level input for this frame. */
            virtual void updateFromState(const InputState& state, float dt) = 0;
    };    
}
