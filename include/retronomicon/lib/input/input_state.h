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
    class InputState {
    public:
        InputState();

        void setAction(const std::string& name, bool active) {
            m_actions[name] = active;
        }

        void setAxis(const std::string& name, float value) { 
            m_axes[name] = value;
        }

        float getAxisValue(const std::string& name) const {
            auto it = m_axes.find(name);
            return it != m_axes.end() ? it->second : 0.0f;
        }

        bool isActionActive(const std::string& name) const {
            auto it = m_actions.find(name);
            return it != m_actions.end() && it->second;
        }

        /** ✅ NEW: returns true only on the frame the action becomes active */
        bool wasActionJustPressed(const std::string& name) const {
            bool curr = isActionActive(name);
            bool prev = false;
            auto it = m_prevActions.find(name);
            if (it != m_prevActions.end()) prev = it->second;

            return curr && !prev;
        }

        /** ✅ NEW: returns true only on the frame the action is released */
        bool wasActionJustReleased(const std::string& name) const {
            bool curr = isActionActive(name);
            bool prev = false;
            auto it = m_prevActions.find(name);
            if (it != m_prevActions.end()) prev = it->second;
            return !curr && prev;
        }

        void clear() {
            for (auto& data : m_actions) data.second = false;
            for (auto& data : m_axes) data.second = 0.0f;
        }


        void setInputMap(InputMap* inputMap) {  
            m_inputMap = inputMap;
        }

        /***************************** To String *****************************/

        /**
         * @brief a method to help people debug this object
         * 
         * @return Brief summary of this object in string
         */
        std::string to_string() const;

    
        /***************************** Operator Overload *****************************/

        /**
         * @brief overloading operator << to call to_string()
         */
        friend std::ostream& operator<<(std::ostream& os, const InputState& obj) {
            return os << obj.to_string();
        }

        void updateFromSDL();

    private:
        std::unordered_map<std::string, bool> m_prevActions;  // ✅ track last frame
        std::unordered_map<std::string, bool> m_actions;      // current frame
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
}


