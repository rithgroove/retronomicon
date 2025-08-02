#include "retronomicon/lib/scene/menu_option.h"

namespace retronomicon::lib::scene {

    MenuOption::MenuOption(std::string label, std::function<void()> onSelect)
        : m_label(std::move(label)), m_onSelect(std::move(onSelect)) {}

    void MenuOption::select() {
        if (m_onSelect) m_onSelect();
    }

    std::string MenuOption::getLabel() {
        return m_label;
    }

    bool MenuOption::isSelectable() {
        return true;
    }

}
