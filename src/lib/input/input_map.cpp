#include "retronomicon/lib/input/input_map.h"

namespace retronomicon::lib::input {

    void InputMap::bindKey(SDL_Scancode key, const string& actionName) {
        keyBindings_[key] = actionName;
    }

    void InputMap::bindAxis(const string& axisName, SDL_Scancode negative, SDL_Scancode positive) {
        axisBindings_[axisName] = { negative, positive };
    }

    string InputMap::getAction(SDL_Scancode key) const {
        auto it = keyBindings_.find(key);
        return (it != keyBindings_.end()) ? it->second : "";
    }

    float InputMap::getAxisValue(const string& axisName, const Uint8* keyboardState) const {
        auto it = axisBindings_.find(axisName);
        if (it == axisBindings_.end()) return 0.0f;

        float value = 0.0f;
        if (keyboardState[it->second.first]) value -= 1.0f;
        if (keyboardState[it->second.second]) value += 1.0f;
        return value;
    }

    const unordered_map<SDL_Scancode, string>& InputMap::getKeyBindings() const {
        return keyBindings_;
    }

    const unordered_map<string, pair<SDL_Scancode, SDL_Scancode>>& InputMap::getAxisBindings() const {
        return axisBindings_;
    }

} // namespace retronomicon::lib::input
