#include "retronomicon/lib/scene/menu/menu_interaction_system.h"

namespace retronomicon::lib::scene::menu {

    MenuInteractionSystem::MenuInteractionSystem(retronomicon::lib::input::InputState* input)
        : inputState(input) {}

    void MenuInteractionSystem::update(float dt, retronomicon::lib::core::Entity* entity) {
        std::vector<retronomicon::lib::core::Entity*> menuItems;

        // Collect menu items
        for (Entity* current : entity->getChilds()) {
            if (current->hasComponent<MenuItemComponent>() &&
                current->hasComponent<SceneChangeComponent>()) {
                menuItems.push_back(current);
            }
        }

        if (menuItems.empty()) return;

        // Navigation
        if (inputState->wasActionJustPressed("up")) {
            if (selectedIndex == 0) {
                selectedIndex = menuItems.size() - 1;
            } else {
                selectedIndex--;
            }
        }
        if (inputState->wasActionJustPressed("down")) {
            selectedIndex = (selectedIndex + 1) % menuItems.size();
        }

        // Apply highlight
        for (size_t i = 0; i < menuItems.size(); i++) {
            auto* menuItem = menuItems[i]->getComponent<MenuItemComponent>();
            menuItem->setSelected(i == selectedIndex);
        }

        // Confirm selection
        if (inputState->wasActionJustPressed("confirm")) {
            auto* sceneChange = menuItems[selectedIndex]->getComponent<SceneChangeComponent>();
            sceneChange->triggered = true;
        }
    }

} // namespace retronomicon::lib::scene::menu
