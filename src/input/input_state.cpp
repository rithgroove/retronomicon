#include "retronomicon/input/input_state.h"
#include <sstream>
#include <iostream>
#include <algorithm> // for std::clamp

namespace retronomicon::input {

    /***************************** Constructor *****************************/

    InputState::InputState()
        : m_rawInput(nullptr), m_inputMap(nullptr) {
        // RawInput must be injected by backend (SDL, Vulkan, etc.)
    }

    /***************************** To String *****************************/

    std::string InputState::to_string() const {
        std::ostringstream oss;
        oss << "[Input State]\n";
        oss << "axes:\n";
        for (const auto& it : m_axes) {
            oss << " - " << it.first << " = " << it.second << "\n";
        }
        oss << "actions:\n";
        for (const auto& it : m_actions) {
            oss << " - " << it.first << " = " << it.second << "\n";
        }
        oss << "prev-actions:\n";
        for (const auto& it : m_prevActions) {
            oss << " - " << it.first << " = " << it.second << "\n";
        }
        return oss.str();
    }

    /***************************** Lifecycle *****************************/

    void InputState::beginFrame() {
        // Store last-frame actions
        m_prevActions = m_actions;

        // Reset axes only, but DO NOT clear actions fully.
        // Instead, mark all actions as false. Backend will re-enable pressed ones.
        for (auto& it : m_actions) {
            it.second = false;
        }

        m_axes.clear();
    }


    void InputState::clear() {
        m_axes.clear();
        m_actions.clear();
    }

    /***************************** Mutators *****************************/

    void InputState::setAction(const std::string& name, bool pressed) {
        m_actions[name] = pressed;
    }

    void InputState::setAxis(const std::string& name, float value) {
        // Clamp to [-1, 1] for normalized axis
        m_axes[name] = std::clamp(value, -1.0f, 1.0f);
    }

    /***************************** Query Methods *****************************/

    bool InputState::isActionActive(const std::string& name) const {
        auto it = m_actions.find(name);
        return it != m_actions.end() && it->second;
    }

    bool InputState::wasActionJustPressed(const std::string& name) const {
        bool now = isActionActive(name);
        auto it = m_prevActions.find(name);
        bool prev = (it != m_prevActions.end()) ? it->second : false;
        return now && !prev;
    }

    bool InputState::wasActionJustReleased(const std::string& name) const {
        bool now = isActionActive(name);
        auto it = m_prevActions.find(name);
        bool prev = (it != m_prevActions.end()) ? it->second : false;
        return !now && prev;
    }

    float InputState::getAxis(const std::string& name) const {
        auto it = m_axes.find(name);
        return (it != m_axes.end()) ? it->second : 0.0f;
    }

} // namespace retronomicon::input
