#include "retronomicon/lib/input/input_state.h"
#include <sstream>
#include <iostream>
/**
 * @brief This namespace is for handling input
 */
namespace retronomicon::lib::input {

    /***************************** Constructor *****************************/

    /**
     *  @brief constructor of Input State
     * 
     * @param rawInput the rawInput class
     * @param inputMap key mapping from SDL to what the game understand
     */
    InputState::InputState(RawInput * rawInput){
        m_rawInput = rawInput;
    }

    /***************************** Destructor *****************************/

    // InputState:~InputState() = default;
    
    /***************************** To String *****************************/
    
    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string InputState::to_string() const{
        std::ostringstream oss;
        oss << "[Input State]\n";
        oss << "axis:\n";
        for (const auto& it : m_axes) {
            oss << " - "<< it.first << " = " << it.second <<"\n";
        }
        oss << "actions:\n";
        for (const auto& it : m_actions) {
            oss << " - "<< it.first << " = " << it.second <<"\n";
        }
        oss << "prev-actions:\n";
        for (const auto& it : m_prevActions) {
            oss << " - "<< it.first << " = " << it.second <<"\n";
        }
        return oss.str();
    }

    /***************************** Main Methods *****************************/
    /**
     * @brief a method to update from SDL Event Pool
     */
    void InputState::updateFromSDL() {
        // Save last frame state before overwriting
        m_prevActions = m_actions;

        // std::cout<<""<<&m_prevActions<<" vs "<<&m_actions <<std::endl;
        m_rawInput->clear();
        m_rawInput->poll();
        const Uint8* keys = m_rawInput->getKeyboardState();
        this->clear();

        // --- Handle actions ---
        // Aggregate all bindings for the same action
        std::unordered_map<std::string, bool> aggregatedActions;

        for (const auto& binding : m_inputMap->getActionBindings()) {
            SDL_Scancode key = binding.first;
            const std::string& actionName = binding.second;

            bool isPressed = keys[key];
            // OR with any previous binding for this action
            aggregatedActions[actionName] = aggregatedActions[actionName] || isPressed;
        }

        // Apply aggregated results
        for (const auto& action : aggregatedActions) {
            this->setAction(action.first, action.second);
        }

        // --- Handle axes ---
        for (const auto& it : m_inputMap->getAxisBindings()) {
            float value = 0.0f;
            for (const auto& it2 : it.second) {
                if (keys[it2.first]) {
                    value += it2.second;
                }
            }
            value = clamp(value, -1.0f, 1.0f);
            this->setAxis(it.first, value);
        }
    }
} // namespace retronomicon::lib::input