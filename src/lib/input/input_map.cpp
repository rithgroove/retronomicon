#include "retronomicon/lib/input/input_map.h"
namespace retronomicon::lib::input {
    InputMap::InputMap(){}

    void InputMap::bindAction(SDL_Scancode key, const std::string& actionName) {
        m_actionBindings[key] = actionName;
    }

    void InputMap::bindAxis(SDL_Scancode key, const std::string& axisName, float weight) {
        m_axisBindings[axisName].emplace_back(key, weight);
    }

    // void InputMap::fill(InputState* state, const Uint8* keyboardState) {
    //     // Clear old state
    //     state->clear();

    //     // Set actions
    //     for (const auto& it : m_actionBindings) {
    //         bool isPressed = keyboardState[it.first];
    //         state->setAction(it.second, isPressed);
    //     }

    //     // Set axes
    //     for (const auto& it : m_axisBindings) {
    //         float value = 0.0f;
    //         for (const auto& it2 : it.second) {
    //             if (keyboardState[it2.first]) {
    //                 value += it2.second;
    //             }
    //         }
    //         value = clamp(value, -1.0f, 1.0f);
    //         state->setAxis(it.first, value);
    //     }
    // }

    const std::unordered_map<SDL_Scancode, std::string>& InputMap::getActionBindings() const {
        return m_actionBindings;
    }

    const std::unordered_map<std::string, std::vector<std::pair<SDL_Scancode, float>>>& InputMap::getAxisBindings() const {
        return m_axisBindings;
    }

} // namespace retronomicon::lib::input
