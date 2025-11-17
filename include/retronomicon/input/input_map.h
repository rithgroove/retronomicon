#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <ostream>
#include <sstream>
#include "retronomicon/input/key.h"

namespace retronomicon::input {

    /**
     * @brief Maps engine Key enums to actions and movement axes.
     *
     * This is a pure data container; RawInput handles current key states,
     * while InputMap translates key presses into named actions or axes.
     */
    class InputMap {
    public:
        /***************************** Constructor *****************************/
        InputMap() = default;

        /***************************** Getter *****************************/
        const std::unordered_map<Key, std::string>& getActionBindings() const {
            return m_actionBindings;
        }

        const std::unordered_map<std::string, std::vector<std::pair<Key, float>>>& getAxisBindings() const {
            return m_axisBindings;
        }

        /***************************** Operator Overload *****************************/
        friend std::ostream& operator<<(std::ostream& os, const InputMap& obj) {
            return os << obj.to_string();
        }

        /***************************** To String *****************************/
        std::string to_string() const {
            std::ostringstream oss;
            oss << "[InputMap]\n";

            oss << "Actions:\n";
            for (const auto& it : m_actionBindings)
                oss << " - Key " << static_cast<int>(it.first) << " -> " << it.second << "\n";

            oss << "Axes:\n";
            for (const auto& axis : m_axisBindings) {
                oss << " - " << axis.first << ":";
                for (const auto& binding : axis.second)
                    oss << " (Key " << static_cast<int>(binding.first) << " = " << binding.second << ")";
                oss << "\n";
            }

            return oss.str();
        }

        /***************************** Action Bindings *****************************/
        void bindAction(Key key, const std::string& actionName) {
            m_actionBindings[key] = actionName;
        }

        /***************************** Axis Bindings *****************************/
        void bindAxis(Key key, const std::string& axisName, float weight) {
            m_axisBindings[axisName].emplace_back(key, weight);
        }

    private:
        /***************************** Attributes *****************************/
        std::unordered_map<Key, std::string> m_actionBindings;
        std::unordered_map<std::string, std::vector<std::pair<Key, float>>> m_axisBindings;
    };

} // namespace retronomicon::input
