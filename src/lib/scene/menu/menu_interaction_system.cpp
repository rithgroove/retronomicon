#include "retronomicon/lib/scene/menu/menu_interaction_system.h"

namespace retronomicon::lib::scene::menu {

    MenuInteractionSystem::MenuInteractionSystem(retronomicon::lib::input::InputState* input)
        : inputState(input) {}

    void MenuInteractionSystem::update(float dt, retronomicon::lib::core::Entity* objects) {
        std::vector<retronomicon::lib::core::Entity*> menuItems;
        retronomicon::lib::core::Entity* current = objects;

        // Collect menu items
        while (current != nullptr) {
            if (current->hasComponent<MenuInputItemComponent>() &&
                current->hasComponent<SceneChangeComponent>()) {
                menuItems.push_back(current);
            }
            current = current->next; // Assuming linked list or array-like iteration
        }

        if (menuItems.empty()) return;

        // Navigation
        if (inputState->isActionTriggered("up")) {
            if (selectedIndex == 0) {
                selectedIndex = menuItems.size() - 1;
            } else {
                selectedIndex--;
            }
        }
        if (inputState->isActionTriggered("down")) {
            selectedIndex = (selectedIndex + 1) % menuItems.size();
        }

        // Apply highlight
        for (size_t i = 0; i < menuItems.size(); i++) {
            auto& menuItem = menuItems[i]->getComponent<MenuInputItemComponent>();
            menuItem.highlighted = (i == selectedIndex);
        }

        // Confirm selection
        if (inputState->isActionTriggered("confirm")) {
            auto& sceneChange = menuItems[selectedIndex]->getComponent<SceneChangeComponent>();
            sceneChange.triggered = true;
        }
    }

} // namespace retronomicon::lib::scene::menu
