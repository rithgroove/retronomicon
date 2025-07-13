#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <SDL.h>
// #include "input_state.h"

/**
 * @brief This namespace is for handling input
 */
namespace retronomicon::lib::input {
    // class InputState;

    class InputMap {
        public:
            InputMap();
            void bindAction(SDL_Scancode key, const std::string& actionName);
            void bindAxis(SDL_Scancode key, const std::string& axisName, float weight);

            // void fill(InputState* state, const Uint8* keyboardState);

            const std::unordered_map<SDL_Scancode, std::string>& getActionBindings() const;
            const std::unordered_map<std::string, std::vector<std::pair<SDL_Scancode, float>>>& getAxisBindings() const;

        private:
            std::unordered_map<SDL_Scancode, std::string> m_actionBindings;
            std::unordered_map<std::string, std::vector<std::pair<SDL_Scancode, float>>> m_axisBindings;
    };

} // namespace retronomicon::lib::input
