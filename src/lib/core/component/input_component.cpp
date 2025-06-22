#include "retronomicon/lib/core/component/input_component.h"

namespace retronomicon::lib::core::component {

    bool InputComponent::isActionActive(const std::string& name) const {
        auto it = m_actions.find(name);
        return it != m_actions.end() && it->second;
    }

    float InputComponent::getAxis(const std::string& name) const {
        auto it = m_axes.find(name);
        return it != m_axes.end() ? it->second : 0.0f;
    }

    void InputComponent::setAction(const std::string& name, bool active) {
        m_actions[name] = active;
    }

    void InputComponent::setAxis(const std::string& name, float value) {
        m_axes[name] = value;
    }

    void InputComponent::clear() {
        for (auto& it : m_actions) it.second = false;
        for (auto& it : m_axes) it.second = 0.0f;
    }

} // namespace retronomicon::lib::core::component
