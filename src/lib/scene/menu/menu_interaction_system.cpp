#include "retronomicon/lib/scene/menu/menu_interaction_system.h"
#include <iostream>
namespace retronomicon::lib::scene::menu {

    MenuInteractionSystem::MenuInteractionSystem(retronomicon::lib::input::InputState* input)
        : m_inputState(input) {}

    void MenuInteractionSystem::update(float dt, retronomicon::lib::core::Entity* entity) {
        std::vector<retronomicon::lib::core::Entity*> menuItems;
    
        // std::cout << "check point 1" <<std::endl;
        // Collect menu items
        for (Entity* current : entity->getChilds()) {
            if (current->hasComponent<MenuItemComponent>() &&
                current->hasComponent<SceneChangeComponent>()) {
                menuItems.push_back(current);
            }
        }

        // std::cout << "check point 2" <<std::endl;
        if (menuItems.empty()){
            // traverse to find the menu options
            // std::cout << "check point 3" <<std::endl;
            for (Entity* current : entity->getChilds()) {
                this->update(dt,current);
            }
        }else{

            m_inputState->updateFromSDL();
            // std::cout<<m_inputState->to_string()<<std::endl;
            if (m_inputState->wasActionJustPressed("up")) {
                std::cout << "up pressed" <<std::endl;
                if (selectedIndex == 0) {
                    selectedIndex = menuItems.size() - 1;
                } else {
                    selectedIndex--;
                }
            }
            if (m_inputState->wasActionJustPressed("down")) {
                std::cout << "down pressed" <<std::endl;
                selectedIndex = (selectedIndex + 1) % menuItems.size();
            }

            // Apply highlight
            for (size_t i = 0; i < menuItems.size(); i++) {
                auto* menuItem = menuItems[i]->getComponent<MenuItemComponent>();
                menuItem->setSelected(i == selectedIndex);
            }

            // Confirm selection
            if (m_inputState->wasActionJustPressed("confirm")) {
                std::cout << "confirm pressed" <<std::endl;
                auto* sceneChange = menuItems[selectedIndex]->getComponent<SceneChangeComponent>();
                sceneChange->triggered = true;
            }
        }
       
    }

} // namespace retronomicon::lib::scene::menu
