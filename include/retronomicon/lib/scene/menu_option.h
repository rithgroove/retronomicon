#pragma once

#include <string>
#include <functional>

namespace retronomicon::lib::scene {

    class MenuOption {
    public:
        MenuOption(std::string label, std::function<void()> onSelect);

        virtual ~MenuOption() = default;

        virtual void select();           // Calls the callback
        virtual std::string getLabel();  // For drawing
        virtual bool isSelectable();     // Override for things like disabled options

    protected:
        std::string m_label;
        std::function<void()> m_onSelect;
    };

}