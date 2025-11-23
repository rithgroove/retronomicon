#pragma once
#include <unordered_map>
#include <stdio.h>
#include <string>
#include "raw_input.h"
#include "input_map.h"
#include <iostream>
#pragma once

#include <string>
#include <unordered_map>
#include <memory>

namespace retronomicon::input {

    class RawInput;   // Forward declare (backend provides implementation)
    class InputMap;   // Forward declare

    class InputState {
    public:
        /***************************** Constructor *****************************/
        InputState();

        InputState(std::shared_ptr<RawInput> rawInput,std::shared_ptr<InputMap >inputMap);
        /***************************** Lifecycle *****************************/
        void beginFrame();   // Called at start of each frame
        void clear();        // Clears actions & axes

        /***************************** Mutators *****************************/
        void setAction(const std::string& name, bool pressed);
        void setAxis(const std::string& name, float value);
        void setRawInput(std::shared_ptr<RawInput> rawInput){m_rawInput= rawInput;}
        void setInputMap(std::shared_ptr<InputMap> inputMap){m_inputMap= inputMap;}

        /***************************** Query Methods *****************************/
        bool isActionActive(const std::string& name) const;
        bool wasActionJustPressed(const std::string& name) const;
        bool wasActionJustReleased(const std::string& name) const;
        float getAxis(const std::string& name) const;

        /***************************** Debug *****************************/
        std::string to_string() const;

    private:
        std::shared_ptr<RawInput> m_rawInput;     // Injected backend raw input
        std::shared_ptr<InputMap >m_inputMap;     // Maps raw input -> game actions/axes

        std::unordered_map<std::string, bool> m_actions;
        std::unordered_map<std::string, bool> m_prevActions;
        std::unordered_map<std::string, float> m_axes;
    };

} // namespace retronomicon::input

