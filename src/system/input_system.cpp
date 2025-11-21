#include "retronomicon/system/input_system.h"
#include "retronomicon/component/input_component.h"

namespace retronomicon::system {

    using retronomicon::component::InputComponent;
    using retronomicon::input::InputAction;
    using retronomicon::input::InputState;
    using retronomicon::entity::Entity;

    InputSystem::InputSystem() {}

    InputSystem::InputSystem(std::shared_ptr<InputState> state)
        : m_inputState(std::move(state)) {

        }

    std::string InputSystem::to_string() const {
        return "[InputSystem]\n";
    }

    void InputSystem::update(float dt, std::weak_ptr<Entity> entity) {
        if (!m_inputState) return;

        if (auto e = entity.lock()) {

            // 1. Check for InputComponent
            auto comp = e->getComponent<InputComponent>();
            if (comp) {
                // Iterate all bound actions
                for (const auto& [actionName, actionPtr] : comp->getBindings()) {
                    if (!actionPtr) continue;

                    // Check the current input state
                    if (m_inputState->wasActionJustPressed(actionName)) {
                        actionPtr->execute(e, *m_inputState);
                    }
                }
            }

            // 2. Recurse into children
            for (auto& child : e->getChildren()) {
                update(dt, child);
            }
        }
    }

} // namespace retronomicon::system
