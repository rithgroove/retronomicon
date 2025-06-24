#include "retronomicon/lib/input/input_state.h"

namespace retronomicon::lib::input {

    InputState::InputState(){}
    
    void InputState::setAction(const string& name, bool active) {
        actions_[name] = active;
    }

    void InputState::setAxis(const string& name, float value) {
        axes_[name] = value;
    }

    bool InputState::isActionActive(const string& name) const {
        auto it = actions_.find(name);
        return it != actions_.end() && it->second;
    }

    float InputState::getAxisValue(const string& name) const {
        auto it = axes_.find(name);
        return it != axes_.end() ? it->second : 0.0f;
    }

    void InputState::clear() {
        for (auto& data : actions_) data.second = false;
        for (auto& data : axes_) data.second = 0.0f;
    }

    const unordered_map<string, bool>& InputState::getActions() const {
        return actions_;
    }

    const unordered_map<string, float>& InputState::getAxes() const {
        return axes_;
    }

} // namespace retronomicon::lib::input