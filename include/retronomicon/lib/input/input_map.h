#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <SDL.h>

#include "retronomicon/lib/input/input_state.h"
using namespace std;
namespace retronomicon::lib::input {

    class InputMap {
        public:
            InputMap();
            void bindAction(SDL_Scancode key, const string& actionName);
            void bindAxis(SDL_Scancode key, const string& axisName, float weight);

            void fill(InputState* state, const Uint8* keyboardState) const;

            const unordered_map<SDL_Scancode, string>& getActionBindings() const;
            const unordered_map<string, vector<pair<SDL_Scancode, float>>>& getAxisBindings() const;

        private:
            unordered_map<SDL_Scancode, string> m_actionBindings;
            unordered_map<string, vector<pair<SDL_Scancode, float>>> m_axisBindings;
    };

    template <typename T>
    const T& clamp(const T& v, const T& lo, const T& hi) {
        return (v < lo) ? lo : (hi < v) ? hi : v;
    }
} // namespace retronomicon::lib::input
