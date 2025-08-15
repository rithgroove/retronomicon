#pragma once

#include <string>
#include <functional>
#include "retronomicon/lib/scene/scene_change_component.h"
#include "retronomicon/lib/core/component.h"

namespace retronomicon::lib::scene::menu {
    using retronomicon::lib::scene::SceneChangeComponent;
    using retronomicon::lib::core::Component;
    class MenuOption : public Component{
    public:
        MenuOption(std::string label, SceneChangeComponent* component);

        virtual ~MenuOption() = default;
        void update(float dt)override;
        virtual void select();           // Calls the callback
        virtual std::string getLabel();  // For drawing
        virtual bool isSelectable();     // Override for things like disabled options
        bool selected = false;

    protected:
        SceneChangeComponent* m_component;
        std::string m_label;
    };

} // namespace retronomicon::lib::scene
