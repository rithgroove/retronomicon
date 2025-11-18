#pragma once

#include <memory>
#include <string>
#include "retronomicon/system/system.h"
#include "retronomicon/entity/entity.h"
#include "retronomicon/input/input_state.h"
#include "retronomicon/component/input_component.h"

namespace retronomicon::system {

    class InputSystem : public System {
    public:
        InputSystem();
        explicit InputSystem(std::shared_ptr<retronomicon::input::InputState> state);
        ~InputSystem() override = default;

        std::string to_string() const;

        /**
         * @brief Main ECS update. Traverses the entity tree and triggers input actions.
         */
        void update(float dt, std::weak_ptr<retronomicon::entity::Entity> entity) override;

    private:
        std::shared_ptr<retronomicon::input::InputState> m_inputState;
    };

} // namespace retronomicon::system
