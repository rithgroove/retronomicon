#pragma once

#include <memory>
#include "retronomicon/lib/core/system.h"
#include "retronomicon/lib/core/entity.h"
#include "retronomicon/lib/input/input_state.h"
#include "menu_item_component.h"
#include "retronomicon/lib/scene/scene_change_component.h"
#include "retronomicon/lib/core/transform_component.h"

namespace retronomicon::lib::scene::menu {
    using retronomicon::lib::scene::SceneChangeComponent;
    using retronomicon::lib::core::Entity;
    using retronomicon::lib::input::InputState;
    class MenuInteractionSystem : public retronomicon::lib::core::System {

    public:
        MenuInteractionSystem(std::shared_ptr<InputState> input);

        void update(float dt, retronomicon::lib::core::Entity* objects) override;
        // bool m_isUpdating= false;
    private:
        std::shared_ptr<InputState> m_inputState;
        size_t selectedIndex = 0;
    };

} // namespace retronomicon::lib::scene::menu
