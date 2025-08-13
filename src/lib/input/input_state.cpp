#include "retronomicon/lib/input/input_state.h"
#include <sstream>

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
    InputState::InputState(RawInput * rawInput,InputMap* inputMap){
        m_rawInput = rawInput;
        m_inputMap = inputMap;
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
        return oss.str();
    }

    /***************************** Main Methods *****************************/

    /**
     * @brief a method to update from SDL Event Pool
     */
    void InputState::updateFromSDL(){
        m_rawInput->clear();
        m_rawInput->poll();
        const auto& events = m_rawInput->getEvents();
        const Uint8* keys = m_rawInput->getKeyboardState();
        this->clear();


        // Set actions
        for (const auto& it : m_inputMap->getActionBindings()) {
            bool isPressed = keys[it.first];
            this->setAction(it.second, isPressed);
        }

        // Set axes
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


        // for (const auto& it : m_actions) {
        //     std::cout << it.first << ": " << (it.second ? "pressed" : "released") << endl;
        // }

        // for (const auto& it : m_axes) {
        //     std::cout << it.first << ": " << it.second << endl;
        // }
    }
} // namespace retronomicon::lib::input