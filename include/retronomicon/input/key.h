#pragma once

namespace retronomicon::input {

    /**
     * @brief Unified key enumeration for engine-level input handling.
     *
     * This enum abstracts away backend-specific key codes (SDL, GLFW, Win32, etc.)
     * into a stable and portable set understood by the engine.  
     * It is used by:
     *
     *  - RawInput → reports hardware key states
     *  - InputMap → maps keys to actions/axes
     *  - InputState → stores final per-frame state
     *
     * New categories (gamepads, touch, etc.) can be added without breaking
     * existing bindings.
     */
    enum class Key {
        Unknown = 0,

        // ------------------------------------------------------------
        // Alphabet
        // ------------------------------------------------------------
        A, B, C, D, E, F, G,
        H, I, J, K, L, M, N,
        O, P, Q, R, S, T, U,
        V, W, X, Y, Z,

        // ------------------------------------------------------------
        // Number row (0–9)
        // ------------------------------------------------------------
        Num0, Num1, Num2, Num3, Num4,
        Num5, Num6, Num7, Num8, Num9,

        // ------------------------------------------------------------
        // Function keys
        // ------------------------------------------------------------
        F1, F2, F3, F4, F5, F6,
        F7, F8, F9, F10, F11, F12,

        // ------------------------------------------------------------
        // Modifier keys
        // ------------------------------------------------------------
        LeftShift, RightShift,
        LeftControl, RightControl,
        LeftAlt, RightAlt,
        LeftSuper, RightSuper, ///< Windows key / Command key

        // ------------------------------------------------------------
        // Arrow keys
        // ------------------------------------------------------------
        Up, Down, Left, Right,

        // ------------------------------------------------------------
        // Special keys
        // ------------------------------------------------------------
        Space,
        Enter,
        Escape,
        Tab,
        Backspace,
        DeleteKey,
        Insert,
        Home,
        End,
        PageUp,
        PageDown,

        // ------------------------------------------------------------
        // Punctuation / symbols
        // ------------------------------------------------------------
        Minus,
        Plus,
        Comma,
        Period,
        Slash,
        Semicolon,
        Apostrophe,
        LeftBracket,
        RightBracket,
        Backslash,
        Grave,

        // ------------------------------------------------------------
        // Numpad keys
        // ------------------------------------------------------------
        Numpad0, Numpad1, Numpad2, Numpad3, Numpad4,
        Numpad5, Numpad6, Numpad7, Numpad8, Numpad9,
        NumpadAdd,
        NumpadSubtract,
        NumpadMultiply,
        NumpadDivide,
        NumpadEnter,
        NumpadDecimal,

        // ------------------------------------------------------------
        // Mouse buttons
        // ------------------------------------------------------------
        MouseLeft,
        MouseRight,
        MouseMiddle,

        // (Gamepad button enums may be added later)
    };

} // namespace retronomicon::input


namespace std {

    /**
     * @brief Hash function specialization so Key can be used in unordered_map.
     */
    template<>
    struct hash<retronomicon::input::Key> {
        std::size_t operator()(const retronomicon::input::Key& k) const noexcept {
            return static_cast<std::size_t>(k);
        }
    };

}
