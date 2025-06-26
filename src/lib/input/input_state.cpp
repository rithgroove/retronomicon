#include "retronomicon/lib/input/input_state.h"

namespace retronomicon::lib::input {

    InputState::InputState(RawInput * rawInput,InputMap* inputMap){
        m_rawInput = rawInput;
        m_inputMap = inputMap;
    }
    
    void InputState::setAction(const string& name, bool active) {
        if (!m_actions[name]){ // if already true, do not turn it into false 
            m_actions[name] = active;
        }
    }

    void InputState::setAxis(const string& name, float value) {
        m_axes[name] = value;
    }

    bool InputState::isActionActive(const string& name) const {
        auto it = m_actions.find(name);
        return it != m_actions.end() && it->second;
    }

    float InputState::getAxisValue(const string& name) const {
        auto it = m_axes.find(name);
        return it != m_axes.end() ? it->second : 0.0f;
    }

    void InputState::clear() {
        for (auto& data : m_actions) data.second = false;
        for (auto& data : m_axes) data.second = 0.0f;
    }

    const unordered_map<string, bool>& InputState::getActions() const {
        return m_actions;
    }

    const unordered_map<string, float>& InputState::getAxes() const {
        return m_axes;
    }

} // namespace retronomicon::lib::input