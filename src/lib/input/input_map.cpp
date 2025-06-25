#include "retronomicon/lib/input/input_map.h"
namespace retronomicon::lib::input {
    InputMap::InputMap(){}

    void InputMap::bindAction(SDL_Scancode key, const string& actionName) {
        m_actionBindings[key] = actionName;
    }

    void InputMap::bindAxis(SDL_Scancode key, const string& axisName, float weight) {
        m_axisBindings[axisName].emplace_back(key, weight);
    }

    void InputMap::fill(InputState* state, const Uint8* keyboardState) const {
        // Clear old state
        state->clear();

        // Set actions
        for (const auto& [key, actionName] : m_actionBindings) {
            bool isPressed = keyboardState[key];
            state->setAction(actionName, isPressed);
        }

        // Set axes
        for (const auto& [axisName, pairs] : m_axisBindings) {
            float value = 0.0f;
            for (const auto& [key, weight] : pairs) {
                if (keyboardState[key]) {
                    value += weight;
                }
            }
            value = clamp(value, -1.0f, 1.0f);
            state->setAxis(axisName, value);
        }
    }

    const unordered_map<SDL_Scancode, string>& InputMap::getActionBindings() const {
        return m_actionBindings;
    }

    const unordered_map<string, vector<pair<SDL_Scancode, float>>>& InputMap::getAxisBindings() const {
        return m_axisBindings;
    }

} // namespace retronomicon::lib::input
