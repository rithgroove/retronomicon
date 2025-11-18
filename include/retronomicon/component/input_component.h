#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "retronomicon/input/input_action.h"
#include "component.h"

namespace retronomicon::component {

    /**
     * @brief Component holding input-triggered actions for an entity.
     *
     * InputSystem invokes the bound InputAction instances when their
     * corresponding engine actions are triggered.
     */
    class InputComponent : public retronomicon::component::Component {
    public:
        InputComponent() = default;
        virtual ~InputComponent() = default;

        /**
         * @brief Bind an action name to an InputAction handler.
         */
        void bindAction(const std::string& actionName,
                        std::unique_ptr<retronomicon::input::InputAction> action);

        /**
         * @brief Retrieve the action handler for a given name.
         * Returns nullptr if not found.
         */
        retronomicon::input::InputAction*
        getAction(const std::string& actionName) const;
        const auto& getBindings() const { return m_actions; }       

    private:
        // e.g. "Jump" -> JumpAction, "Shoot" -> ShootAction
        std::unordered_map<std::string,
            std::unique_ptr<retronomicon::input::InputAction>> m_actions;
    };

} // namespace retronomicon::component
