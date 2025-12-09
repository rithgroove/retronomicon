#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <iostream>

#include "raw_input.h"
#include "input_map.h"

namespace retronomicon::input {

    class RawInput;   ///< Backend-provided raw hardware input.
    class InputMap;   ///< Maps raw input to game-level actions & axes.

    /**
     * @brief Holds high-level input state for the current frame.
     *
     * InputState is the final step in the input pipeline:
     *
     *  RawInput (hardware) → InputMap (mapping rules) → **InputState (results)**
     *
     * It maintains:
     *  - **Actions** (binary on/off)
     *  - **Axes** (float values, often -1..1)
     *  - **Previous frame state** for detecting transitions
     *
     * Frame lifecycle:
     *  1. `beginFrame()` copies current actions into `m_prevActions`.
     *  2. `clear()` resets current actions & axes.
     *  3. `InputMap.updateFromRawInput()` populates new values.
     *  4. Game systems query `isActionActive`, `wasActionJustPressed`, etc.
     */
    class InputState {
    public:
        /***************************** Constructor *****************************/

        /**
         * @brief Default constructor (raw input + map must be set later).
         */
        InputState();

        /**
         * @brief Construct with raw input backend and input mapping.
         *
         * @param rawInput Raw device input provider.
         * @param inputMap Mapping rules from keys to game actions/axes.
         */
        InputState(std::shared_ptr<RawInput> rawInput,
                   std::shared_ptr<InputMap> inputMap);

        /***************************** Lifecycle *****************************/

        /**
         * @brief Begin frame: store old actions for transition checks.
         */
        void beginFrame();

        /**
         * @brief Clear actions and axes before populating new input values.
         */
        void clear();

        /***************************** Mutators *****************************/

        /**
         * @brief Set an action's active (pressed) state.
         */
        void setAction(const std::string& name, bool pressed);

        /**
         * @brief Assign a value to an axis.
         */
        void setAxis(const std::string& name, float value);

        /**
         * @brief Inject a RawInput backend implementation.
         */
        void setRawInput(std::shared_ptr<RawInput> rawInput) { m_rawInput = rawInput; }

        /**
         * @brief Set the InputMap responsible for converting raw input.
         */
        void setInputMap(std::shared_ptr<InputMap> inputMap) { m_inputMap = inputMap; }

        /***************************** Query Methods *****************************/

        /**
         * @brief Check if an action is currently active.
         *
         * @param name Action name.
         * @return True if active this frame.
         */
        bool isActionActive(const std::string& name) const;

        /**
         * @brief Check if an action transitioned from inactive → active this frame.
         *
         * Useful for detecting button taps.
         */
        bool wasActionJustPressed(const std::string& name) const;

        /**
         * @brief Check if an action transitioned from active → inactive this frame.
         *
         * Useful for detecting button releases.
         */
        bool wasActionJustReleased(const std::string& name) const;

        /**
         * @brief Get the value of an axis (default 0).
         */
        float getAxis(const std::string& name) const;

        /***************************** Debug *****************************/

        /**
         * @brief Returns a serialized representation of the current input state.
         *
         * Useful for debugging overlays or console logs.
         */
        std::string to_string() const;

    private:
        std::shared_ptr<RawInput> m_rawInput; ///< Hardware input provider.
        std::shared_ptr<InputMap> m_inputMap; ///< Maps RawInput → actions & axes.

        std::unordered_map<std::string, bool>  m_actions;     ///< Current frame actions.
        std::unordered_map<std::string, bool>  m_prevActions; ///< Previous frame actions.
        std::unordered_map<std::string, float> m_axes;        ///< Current axes.
    };

} // namespace retronomicon::input
