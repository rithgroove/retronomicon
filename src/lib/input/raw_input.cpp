#include "retronomicon/lib/input/raw_input.h"

namespace retronomicon::lib::input {

    RawInput::RawInput(){
        m_keyboardState = SDL_GetKeyboardState(nullptr);
        m_mouseX = 0;
        m_mouseY = 0;
        m_mouseButtons = 0;
    }

    void RawInput::poll() {
        m_events.clear();

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            m_events.push_back(event);
        }

        // Update mouse position and buttons
        m_mouseButtons = SDL_GetMouseState(&m_mouseX, &m_mouseY);

        // Keyboard state is updated automatically by SDL_GetKeyboardState
    }

    const vector<SDL_Event>& RawInput::getEvents() const {
        return m_events;
    }

    const Uint8* RawInput::getKeyboardState() const {
        return m_keyboardState;
    }

    int RawInput::getMouseX() const {
        return m_mouseX;
    }

    int RawInput::getMouseY() const {
        return m_mouseY;
    }

    Uint32 RawInput::getMouseButtons() const {
        return m_mouseButtons;
    }

    void RawInput::clear() {
        m_events.clear();
    }

} // namespace retronomicon::lib::input