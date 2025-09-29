#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <ostream>

/**
 * @brief This namespace is for handling input
 */
namespace retronomicon::lib::input {

    /**
     * @brief Generic key identifier (backend translates into this)
     */
    using KeyCode = int; 
    // Could later be replaced with a strong enum if you want type safety

    /**
     * @brief input mapping class
     */
    class InputMap {
    public:
        /***************************** Constructor *****************************/
        InputMap() = default;

        /***************************** Getter *****************************/
        const std::unordered_map<KeyCode, std::string>& getActionBindings() const { 
            return m_actionBindings; 
        }

        const std::unordered_map<std::string, std::vector<std::pair<KeyCode, float>>>& getAxisBindings() const { 
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
            for (const auto& it : m_actionBindings) {
                oss << " - Key " << it.first << " -> " << it.second << "\n";
            }
            oss << "Axes:\n";
            for (const auto& axis : m_axisBindings) {
                oss << " - " << axis.first << ":";
                for (const auto& binding : axis.second) {
                    oss << " (Key " << binding.first << " = " << binding.second << ")";
                }
                oss << "\n";
            }
            return oss.str();
        }

        /***************************** Main methods *****************************/
        void bindAction(KeyCode key, const std::string& actionName) {
            m_actionBindings[key] = actionName;
        }

        void bindAxis(KeyCode key, const std::string& axisName, float weight) {
            m_axisBindings[axisName].emplace_back(key, weight);
        }

    private:
        /***************************** Attribute *****************************/
        std::unordered_map<KeyCode, std::string> m_actionBindings;
        std::unordered_map<std::string, std::vector<std::pair<KeyCode, float>>> m_axisBindings;
    };

} // namespace retronomicon::lib::input
