#include "retronomicon/lib/input/input_keyboard.h"

namespace retronomicon {
    namespace lib{
        namespace input{
            InputKeyboard::InputKeyboard() {
                SDL_InitSubSystem(SDL_INIT_VIDEO);
            }

            InputKeyboard::~InputKeyboard() {
                SDL_QuitSubSystem(SDL_INIT_VIDEO);
            }

            void InputKeyboard::update() {
                m_previousState = m_currentState;

                const Uint8* state = SDL_GetKeyboardState(nullptr);
                for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
                    m_currentState[i] = state[i];
                }
            }

            bool InputKeyboard::isButtonPressed(int keyCode) const {
                auto it = m_currentState.find(keyCode);
                auto prevIt = m_previousState.find(keyCode);
                return it != m_currentState.end() && it->second &&
                       (prevIt == m_previousState.end() || !prevIt->second);
            }

            bool InputKeyboard::isButtonReleased(int keyCode) const {
                auto it = m_currentState.find(keyCode);
                auto prevIt = m_previousState.find(keyCode);
                return prevIt != m_previousState.end() && prevIt->second &&
                       (it == m_currentState.end() || !it->second);
            }

            bool InputKeyboard::isButtonHeld(int keyCode) const {
                auto it = m_currentState.find(keyCode);
                return it != m_currentState.end() && it->second;
            }
        } // namespace input
    } // namespace lib
} // namespace retronomicon