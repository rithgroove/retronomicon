#pragma once

#include <string>
#include <functional>
#include "retronomicon/lib/scene/scene_change_component.h"

namespace retronomicon::lib::scene::menu {
    using retronomicon::lib::scene::SceneChangeComponent;
    class MenuOption {
    public:
        MenuOption(std::string label, SceneChangeComponent* component);

        virtual ~MenuOption() = default;

        virtual void select();           // Calls the callback
        virtual std::string getLabel();  // For drawing
        virtual bool isSelectable();     // Override for things like disabled options

    protected:
        SceneChangeComponent* m_component;
        std::string m_label;
    };

} // namespace retronomicon::lib::scene
