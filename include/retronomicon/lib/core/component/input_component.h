#pragma once
#include <unordered_map>
#include <string>
#include "component.h"
namespace retronomicon::lib::core::component {

    class InputComponent : public Component{
        public:
            // Accessors
            bool isActionActive(const std::string& name) const;
            float getAxis(const std::string& name) const;

            // Modifiers
            void setAction(const std::string& name, bool active);
            void setAxis(const std::string& name, float value);
            void clear();
            void update(float dt) override;

        private:
            std::unordered_map<std::string, bool> m_actions;
            std::unordered_map<std::string, float> m_axes;

            // Grant friend access to systems or ECS if necessary
            //friend class retronomicon::lib::core::system::InputSystem;
    };

} // namespace retronomicon::lib::core::component