#include "retronomicon/lib/scene/menu_option.h"
#include <iostream>
namespace retronomicon::lib::scene {

    MenuOption::MenuOption(std::string label, SceneChangeComponent* component)
        : m_label(std::move(label)), m_component(std::move(component)) {
    }


    void MenuOption::select() {
        std::cout<<"lho kok masuk"<<std::endl;
        this->m_component->triggered = true;
    }

    std::string MenuOption::getLabel() {
        return m_label;
    }

    bool MenuOption::isSelectable() {
        return true;
    }

}
