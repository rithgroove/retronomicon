#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <ostream>
#include <sstream>

#include "key.h"
#include "raw_input.h"
#include "input_state.h"

namespace retronomicon::input {
    class InputState;
    /**
     * @brief Maps engine Key enums to actions and axes.
     *
     * RawInput provides backend-specific key states.
     * InputMap converts them into engine-level actions & axes.
     */
    class InputMap {
    public:
        InputMap() = default;

        /***************************** Getters *****************************/
        const std::unordered_map<Key, std::string>& getActionBindings() const {
            return m_actionBindings;
        }

        const std::unordered_map<std::string, std::vector<std::pair<Key, float>>>&
        getAxisBindings() const {
            return m_axisBindings;
        }

        /***************************** To String *****************************/
        std::string toString() const {
            std::ostringstream oss;
            oss << "[InputMap]\n";

            oss << "Actions:\n";
            for (const auto& it : m_actionBindings)
                oss << " - Key " << static_cast<int>(it.first)
                    << " -> " << it.second << "\n";

            oss << "Axes:\n";
            for (const auto& axis : m_axisBindings) {
                oss << " - " << axis.first << ":";
                for (const auto& binding : axis.second)
                    oss << " (Key " << static_cast<int>(binding.first)
                        << " = " << binding.second << ")";
                oss << "\n";
            }

            return oss.str();
        }

        friend std::ostream& operator<<(std::ostream& os, const InputMap& obj) {
            return os << obj.toString();
        }

        /***************************** Bindings *****************************/
        void bindAction(Key key, const std::string& actionName) {
            m_actionBindings[key] = actionName;
        }

        void bindAxis(Key key, const std::string& axisName, float weight) {
            m_axisBindings[axisName].emplace_back(key, weight);
        }

        /***************************** The main function *****************************/
        /**
         * @brief Update InputState using any RawInput backend.
         */
        void updateFromRawInput(const RawInput& raw, InputState& state) const;

    private:
        std::unordered_map<Key, std::string> m_actionBindings;
        std::unordered_map<std::string, std::vector<std::pair<Key, float>>> m_axisBindings;
    };

} // namespace retronomicon::input
