#include "retronomicon/lib/input/raw_input.h"

namespace retronomicon::lib::input {

    RawInput::RawInput()
        : keyboardState_(SDL_GetKeyboardState(nullptr)),
          mouseX_(0),
          mouseY_(0),
          mouseButtons_(0) {}

    void RawInput::poll() {
        events_.clear();

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            events_.push_back(event);
        }

        // Update mouse position and buttons
        mouseButtons_ = SDL_GetMouseState(&mouseX_, &mouseY_);

        // Keyboard state is updated automatically by SDL_GetKeyboardState
    }

    const std::vector<SDL_Event>& RawInput::getEvents() const {
        return events_;
    }

    const Uint8* RawInput::getKeyboardState() const {
        return keyboardState_;
    }

    int RawInput::getMouseX() const {
        return mouseX_;
    }

    int RawInput::getMouseY() const {
        return mouseY_;
    }

    Uint32 RawInput::getMouseButtons() const {
        return mouseButtons_;
    }

    void RawInput::clear() {
        events_.clear();
    }

} // namespace retronomicon::lib::input