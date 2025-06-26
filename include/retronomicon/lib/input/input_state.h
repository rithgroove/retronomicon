#pragma once
#include <unordered_map>
#include <string>
#include "raw_input.h"
#include "input_map.h"
using namespace std;

namespace retronomicon::lib::input {
    class InputState {
        public:
            InputState(RawInput* rawInput, InputMap* inputMap);
            void setAction(const string& name, bool active);
            void setAxis(const string& name, float value);

            bool isActionActive(const string& name) const;
            float getAxisValue(const string& name) const;

            void clear();

            const unordered_map<string, bool>& getActions() const;
            const unordered_map<string, float>& getAxes() const;

        private:
            unordered_map<string, bool> m_actions;
            unordered_map<string, float> m_axes;
            RawInput* m_rawInput;
            InputMap* m_inputMap;
    };

} // namespace retronomicon::lib::input
