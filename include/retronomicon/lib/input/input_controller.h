#pragma once

#include "InputDevice.h"
#include <SDL.h>
#include <unordered_map>

namespace retronomicon {
    namespace lib{
        namespace input{
        class InputController : public InputDevice {
            public:
                InputController();
                ~InputController();

                void update() override;
                bool isButtonPressed(int buttonCode) const override;
                bool isButtonReleased(int buttonCode) const override;
                bool isButtonHeld(int buttonCode) const override;

            private:
                std::unordered_map<int, bool> m_currentState;
                std::unordered_map<int, bool> m_previousState;
            };
        } // namespaceinput
    } // namespace lib
} // namespace retronomicon