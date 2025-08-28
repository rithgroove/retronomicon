#include "retronomicon/lib/scene/menu/menu_interaction_system.h"
#include "retronomicon/lib/audio/sound_effect_component.h"
#include "retronomicon/lib/engine/exit_game_component.h"
#include <iostream>
namespace retronomicon::lib::scene::menu {
    using retronomicon::lib::audio::SoundEffectComponent;
    using retronomicon::lib::engine::ExitGameComponent;
    MenuInteractionSystem::MenuInteractionSystem(retronomicon::lib::input::InputState* input)
        : m_inputState(input) {}

    void MenuInteractionSystem::update(float dt, retronomicon::lib::core::Entity* entity) {
        std::vector<retronomicon::lib::core::Entity*> menuItems;
    
        // std::cout << "check point 1" <<std::endl;
        // Collect menu items
        for (Entity* current : entity->getChilds()) {
            if (current->hasComponent<MenuItemComponent>() &&
                    ( current->hasComponent<SceneChangeComponent>() ||
                      current->hasComponent<ExitGameComponent>() 
                    )
                ) {
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

            // std::cout<<m_inputState->to_string()<<std::endl;
            if (m_inputState->wasActionJustPressed("up")) {
                std::cout << "up pressed" <<std::endl;
                if (selectedIndex == 0) {
                    selectedIndex = menuItems.size() - 1;
                } else {
                    selectedIndex--;
                }
                auto* sfx = menuItems[selectedIndex]->getComponent<SoundEffectComponent>();
                sfx->play();
            }
            if (m_inputState->wasActionJustPressed("down")) {
                std::cout << "down pressed" <<std::endl;
                selectedIndex = (selectedIndex + 1) % menuItems.size();
                auto* sfx = menuItems[selectedIndex]->getComponent<SoundEffectComponent>();
                sfx->play();
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
                if (sceneChange){
                    std::cout << "should be here" <<std::endl;
                    sceneChange->triggered = true;  
                }

                auto* exitComponent = menuItems[selectedIndex]->getComponent<ExitGameComponent>();
                if (exitComponent){
                    exitComponent->activate();
                }

            }
        }
       
    }

} // namespace retronomicon::lib::scene::menu
