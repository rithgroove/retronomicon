#pragma once
#include <SDL.h>
#include <vector>

using namespace std;

namespace retronomicon::lib::input {

    class RawInput {
        public:
            RawInput();

            void poll(); // Poll SDL events

            const vector<SDL_Event>& getEvents() const;
            const Uint8* getKeyboardState() const;
            int getMouseX() const;
            int getMouseY() const;
            Uint32 getMouseButtons() const;

            void clear(); // Clear stored events

        private:
            vector<SDL_Event> m_events;
            const Uint8* m_keyboardState;
            int m_mouseX;
            int m_mouseY;
            Uint32 m_mouseButtons;
    };

} // namespace retronomicon::lib::input