#pragma once
#include <unordered_map>
#include <stdio.h>
#include <string>
#include "raw_input.h"
#include "input_map.h"
#include <iostream>

/**
 * @brief This namespace is for handling input
 */
namespace retronomicon::lib::input {
    // forward declaration
    class InputMap;

    /**
     * @brief input state class that define if list of actions is triggered or not
     */
    class InputState {
        public:
            /***************************** Constructor *****************************/

            /**
             *  @brief constructor of Input State
             * 
             * @param rawInput the rawInput class
             * @param inputMap key mapping from SDL to what the game understand
             */
            InputState(RawInput* rawInput, InputMap* inputMap);

            /***************************** Destructor *****************************/

            // ~InputState();

            /***************************** Setter *****************************/

            /**
             * @brief set an action to active. if already active you cannot turn it to false
             * the main reason is several keys may map to the same state.
             * so you need to call reset() if you want to set to false()
             * 
             * @param active boolean where if a certain input is triggered = true, if not =false
             */
            void setAction(const std::string& name, bool active){
                // if already true, do not turn it into false 
                if (!m_actions[name]){ 
                    m_actions[name] = active;
                }
            }

            /**
             * @brief set an axis value
             * 
             * @param value of an axis (float to handle a joystick)
             */
            void setAxis(const std::string& name, float value) { m_axes[name] = value;}

            /***************************** Getter *****************************/

            /**
             * @brief a method to get the named axis value 
             * 
             * @param the name of the axis
             */
            float getAxisValue(const std::string& name) const {
                auto it = m_axes.find(name);
                return it != m_axes.end() ? it->second : 0.0f;
            }

            /**
             * @brief a method to get all actions 
             */
            const std::unordered_map<std::string, bool>& getActions() const {
                return m_actions;
            }

            /**
             * @brief a method to get all axis value 
             */
            const std::unordered_map<std::string, float>& getAxes() const {
                return m_axes;
            }

            /***************************** Utility *****************************/

            /**
             * @brief a method to check if an action is flagged as true
             * 
             * @param name of the action
             */
            bool isActionActive(const std::string& name) const{
                auto it = m_actions.find(name);
                return it != m_actions.end() && it->second;
            }

            /**
             * @brief a method to clear all state
             */
            void clear(){
                for (auto& data : m_actions) data.second = false;
                for (auto& data : m_axes) data.second = 0.0f;
            }

            /***************************** Main Method *****************************/

            /**
             * @brief a method to update from SDL Event Pool
             */
            void updateFromSDL();


        private:
            /***************************** Attribute *****************************/
            std::unordered_map<std::string, bool> m_actions;
            std::unordered_map<std::string, float> m_axes;
            RawInput* m_rawInput;
            InputMap* m_inputMap;
    };

    /**
     * @brief template for clamp function because it's only available on c++20
     * this methods basically limit the value to a certain range.
     * 
     * - if v lower than lo = return lo
     * - if v higher than hi = return hi
     * - if v in between lo and hi = return v
     * 
     * @param v the value
     * @param lo the minimum value
     * @param hi the maximum value
     */
    template <typename T>
    const T& clamp(const T& v, const T& lo, const T& hi) {
        return (v < lo) ? lo : (hi < v) ? hi : v;
    }
} // namespace retronomicon::lib::input
