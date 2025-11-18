#include "retronomicon/component/input_component.h"

namespace retronomicon::component {

    void InputComponent::bindAction(const std::string& actionName,
                                    std::unique_ptr<retronomicon::input::InputAction> action)
    {
        m_actions[actionName] = std::move(action);
    }

    retronomicon::input::InputAction*
    InputComponent::getAction(const std::string& actionName) const
    {
        auto it = m_actions.find(actionName);
        if (it != m_actions.end()) {
            return it->second.get();
        }
        return nullptr;
    }

} // namespace retronomicon::component
