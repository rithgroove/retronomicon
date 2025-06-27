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

    void InputState::updateFromSDL(){
        m_rawInput->clear();
        m_rawInput->poll();
        const auto& events = m_rawInput->getEvents();
        const Uint8* keys = m_rawInput->getKeyboardState();
        this->clear();


        // Set actions
        for (const auto& it : m_inputMap->getActionBindings()) {
            bool isPressed = keys[it.first];
            this->setAction(it.second, isPressed);
        }

        // Set axes
        for (const auto& it : m_inputMap->getAxisBindings()) {
            float value = 0.0f;
            for (const auto& it2 : it.second) {
                if (keys[it2.first]) {
                    value += it2.second;
                }
            }
            value = clamp(value, -1.0f, 1.0f);
            this->setAxis(it.first, value);
        }


        for (const auto& it : m_actions) {
            std::cout << it.first << ": " << (it.second ? "pressed" : "released") << endl;
        }

        for (const auto& it : m_axes) {
            std::cout << it.first << ": " << it.second << endl;
        }
    }
} // namespace retronomicon::lib::input