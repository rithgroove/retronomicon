#include "retronomicon/input/input_map.h"

namespace retronomicon::input {

    void InputMap::updateFromRawInput(std::shared_ptr<RawInput> raw, std::shared_ptr<InputState> state) const
    {

        // --- Actions ---
        for (const auto& [key, actionName] : m_actionBindings) {
            bool pressed = raw->isKeyPressed(key);
            state->setAction(actionName, pressed);
        }

        // --- Axes ---
        for (const auto& [axisName, bindings] : m_axisBindings) {
            float value = 0.f;

            for (const auto& [key, weight] : bindings) {
                if (raw->isKeyPressed(key)) {
                    value += weight;
                }
            }

            state->setAxis(axisName, value);
        }
    }

} // namespace retronomicon::input
