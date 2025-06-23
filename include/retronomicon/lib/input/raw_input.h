#pragma once
#include <SDL.h>
#include <vector>

namespace retronomicon::lib::input {

class RawInput {
    public:
        RawInput();

        void poll(); // Poll SDL events

        const std::vector<SDL_Event>& getEvents() const;
        const Uint8* getKeyboardState() const;
        int getMouseX() const;
        int getMouseY() const;
        Uint32 getMouseButtons() const;

        void clear(); // Clear stored events

    private:
        std::vector<SDL_Event> events_;
        const Uint8* keyboardState_;
        int mouseX_;
        int mouseY_;
        Uint32 mouseButtons_;
    };

} // namespace retronomicon::lib::input