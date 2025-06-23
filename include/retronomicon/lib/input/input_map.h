#pragma once
#include <unordered_map>
#include <string>
#include <SDL.h>

using namespace std;
namespace retronomicon::lib::input {

    class InputMap {
        public:
            void bindKey(SDL_Scancode key, const string& actionName);
            void bindAxis(const string& axisName, SDL_Scancode negative, SDL_Scancode positive);

            string getAction(SDL_Scancode key) const;
            float getAxisValue(const string& axisName, const Uint8* keyboardState) const;

            const unordered_map<SDL_Scancode, string>& getKeyBindings() const;
            const unordered_map<string, pair<SDL_Scancode, SDL_Scancode>>& getAxisBindings() const;

        private:
            unordered_map<SDL_Scancode, string> keyBindings_;
            unordered_map<string, pair<SDL_Scancode, SDL_Scancode>> axisBindings_;
    };

} // namespace retronomicon::lib::input