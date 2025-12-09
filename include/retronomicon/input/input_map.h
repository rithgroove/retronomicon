#pragma once

#include <unordered_map>
#include <vector>
#include <memory>
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
     * @brief Maps physical input keys to high-level game actions and axes.
     *
     * The input pipeline works like this:
     *  1. **RawInput** provides backend-specific device state (SDL, GLFW, etc.).
     *  2. **InputMap** translates raw keys into engine-level:
     *       - *Actions* (`Jump`, `Confirm`, `Pause`)  
     *       - *Axes* (`MoveX`, `MoveY`) with weighted contributions.
     *  3. **InputState** stores the results for systems and gameplay logic.
     *
     * Key concepts:
     *  - **Action Binding**: A single key → a single action name.
     *  - **Axis Binding**: A key contributes a value (weight) to an axis.
     *
     * Example:
     * @code
     * inputMap.bindAction(Key::Enter, "Confirm");
     * inputMap.bindAxis(Key::A, "MoveX", -1.0f);
     * inputMap.bindAxis(Key::D, "MoveX",  1.0f);
     * @endcode
     */
    class InputMap {
    public:
        InputMap() = default;

        /***************************** Getters *****************************/

        /**
         * @brief Get all action bindings.
         *
         * @return Map from key → action name.
         */
        const std::unordered_map<Key, std::string>& getActionBindings() const {
            return m_actionBindings;
        }

        /**
         * @brief Get all axis bindings.
         *
         * Each axis has a list of `(Key, weight)` pairs.
         */
        const std::unordered_map<std::string,
            std::vector<std::pair<Key, float>>>& getAxisBindings() const {
            return m_axisBindings;
        }

        /***************************** Debug String *****************************/

        /**
         * @brief Returns a human-readable debug string of the entire input map.
         */
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

        /**
         * @brief Bind a key to a named action.
         *
         * @param key        Physical key.
         * @param actionName Logical action name (e.g., `"Jump"`).
         */
        void bindAction(Key key, const std::string& actionName) {
            m_actionBindings[key] = actionName;
        }

        /**
         * @brief Bind a key to contribute to a named axis.
         *
         * @param key     Physical key.
         * @param axisName Name of the axis (e.g., `"MoveX"`).
         * @param weight   Contribution when the key is pressed.
         */
        void bindAxis(Key key, const std::string& axisName, float weight) {
            m_axisBindings[axisName].emplace_back(key, weight);
        }

        /***************************** Mapping Logic *****************************/

        /**
         * @brief Convert RawInput key states into high-level InputState.
         *
         * Steps:
         *  - Check every action binding:
         *      If key is pressed → mark action as active in InputState.
         *  - Compute every axis:
         *      Sum weighted key contributions.
         *
         * @param raw   The raw hardware input backend.
         * @param state The InputState instance to populate.
         */
        void updateFromRawInput(std::shared_ptr<RawInput> raw,
                                std::shared_ptr<InputState> state) const;

    private:
        /**
         * @brief Maps a key to a named action.
         */
        std::unordered_map<Key, std::string> m_actionBindings;

        /**
         * @brief Maps an axis name to a list of `(Key, weight)` pairs.
         */
        std::unordered_map<std::string, std::vector<std::pair<Key, float>>> m_axisBindings;
    };

} // namespace retronomicon::input
