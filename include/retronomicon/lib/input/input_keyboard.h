#pragma once

#include "input_device.h"
#include <SDL.h>
#include <unordered_map>

namespace retronomicon {
    namespace lib{
        namespace input{
            class InputKeyboard : public InputDevice {
                public:
                    InputKeyboard();
                    ~InputKeyboard();

                    void update() override;
                    bool isButtonPressed(int keyCode) const override;
                    bool isButtonReleased(int keyCode) const override;
                    bool isButtonHeld(int keyCode) const override;

                private:
                    std::unordered_map<int, bool> m_currentState;
                    std::unordered_map<int, bool> m_previousState;
            };
        } // namespaceinput
    } // namespace lib
} // namespace retronomicon