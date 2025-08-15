#pragma once

#include "retronomicon/lib/core/system.h"
#include "retronomicon/lib/input/input_state.h"
#include "retronomicon::lib::input::menu_input_item_component.h"
#include "retronomicon/lib/input/scene_change_component.h"
#include "retronomicon/lib/core/transform_component.h"

namespace retronomicon::lib::scene::menu {

    class MenuInteractionSystem : public retronomicon::lib::core::System {
    private:
        retronomicon::lib::input::InputState* inputState;
        size_t selectedIndex = 0;

    public:
        MenuInteractionSystem(retronomicon::lib::input::InputState* input);

        void update(float dt, retronomicon::lib::core::Entity* objects) override;
    };

} // namespace retronomicon::lib::scene::menu
