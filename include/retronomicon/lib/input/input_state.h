#pragma once
#include <unordered_map>
#include <string>

using namespace std;

namespace retronomicon::lib::input {
    class InputState {
        public:
            void setAction(const string& name, bool active);
            void setAxis(const string& name, float value);

            bool isActionActive(const string& name) const;
            float getAxisValue(const string& name) const;

            void clear();

            const unordered_map<string, bool>& getActions() const;
            const unordered_map<string, float>& getAxes() const;

        private:
            unordered_map<string, bool> actions_;
            unordered_map<string, float> axes_;
    };

} // namespace retronomicon::lib::input
