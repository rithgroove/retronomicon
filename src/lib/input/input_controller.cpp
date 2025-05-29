#include "retronomicon/lib/input/input_controller.h"

namespace retronomicon::lib::input{
    InputController::InputController() {
        SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
    }

    InputController::~InputController() {
        SDL_QuitSubSystem(SDL_INIT_GAMECONTROLLER);
    }

    void InputController::update() {
        m_previousState = m_currentState;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_CONTROLLERBUTTONDOWN) {
                m_currentState[event.cbutton.button] = true;
            } else if (event.type == SDL_CONTROLLERBUTTONUP) {
                m_currentState[event.cbutton.button] = false;
            }
        }
    }

    bool InputController::isButtonPressed(int buttonCode) const {
        auto it = m_currentState.find(buttonCode);
        auto prevIt = m_previousState.find(buttonCode);
        return it != m_currentState.end() && it->second &&
               (prevIt == m_previousState.end() || !prevIt->second);
    }

    bool InputController::isButtonReleased(int buttonCode) const {
        auto it = m_currentState.find(buttonCode);
        auto prevIt = m_previousState.find(buttonCode);
        return prevIt != m_previousState.end() && prevIt->second &&
               (it == m_currentState.end() || !it->second);
    }

    bool InputController::isButtonHeld(int buttonCode) const {
        auto it = m_currentState.find(buttonCode);
        return it != m_currentState.end() && it->second;
    }
} // namespace retronomicon