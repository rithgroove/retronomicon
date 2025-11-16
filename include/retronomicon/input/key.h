#pragma once

namespace retronomicon::input {

    enum class Key {
        Unknown = 0,

        // --- Alphabet ---
        A, B, C, D, E, F, G,
        H, I, J, K, L, M, N,
        O, P, Q, R, S, T, U,
        V, W, X, Y, Z,

        // --- Digits ---
        Num0, Num1, Num2, Num3, Num4,
        Num5, Num6, Num7, Num8, Num9,

        // --- Function keys ---
        F1, F2, F3, F4, F5, F6,
        F7, F8, F9, F10, F11, F12,

        // --- Modifiers ---
        LeftShift,
        RightShift,
        LeftControl,
        RightControl,
        LeftAlt,
        RightAlt,
        LeftSuper,
        RightSuper,

        // --- Arrow keys ---
        Up,
        Down,
        Left,
        Right,

        // --- Special keys ---
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

        // --- Punctuation ---
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

        // --- Numpad ---
        Numpad0,
        Numpad1,
        Numpad2,
        Numpad3,
        Numpad4,
        Numpad5,
        Numpad6,
        Numpad7,
        Numpad8,
        Numpad9,
        NumpadAdd,
        NumpadSubtract,
        NumpadMultiply,
        NumpadDivide,
        NumpadEnter,
        NumpadDecimal,

        // --- Mouse buttons ---
        MouseLeft,
        MouseRight,
        MouseMiddle,

        // (Add Xbox/PS inputs later if needed)
    };

} // namespace retronomicon::input
