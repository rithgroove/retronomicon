#pragma once
#include <cstdint>
#include <algorithm>
#include <string>

namespace retronomicon::graphics {

class Color {
    private:
        float m_r;
        float m_g;
        float m_b;
        float m_a;

        static constexpr float clamp(float v) noexcept {
            return v < 0.0f ? 0.0f : (v > 1.0f ? 1.0f : v);
        }

    public:
        // --- Constructors ---
        constexpr Color() noexcept : m_r(1.0f), m_g(1.0f), m_b(1.0f), m_a(1.0f) {}
        constexpr Color(float r, float g, float b, float a = 1.0f) noexcept
            : m_r(clamp(r)), m_g(clamp(g)), m_b(clamp(b)), m_a(clamp(a)) {}

        static constexpr Color fromBytes(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) noexcept {
            return Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
        }

        // --- Getters ---
        constexpr float r() const noexcept { return m_r; }
        constexpr float g() const noexcept { return m_g; }
        constexpr float b() const noexcept { return m_b; }
        constexpr float a() const noexcept { return m_a; }

        // --- Operations ---
        constexpr Color withAlpha(float alpha) const noexcept {
            return Color(m_r, m_g, m_b, alpha);
        }

        constexpr Color operator*(float scalar) const noexcept {
            return Color(clamp(m_r * scalar), clamp(m_g * scalar), clamp(m_b * scalar), clamp(m_a * scalar));
        }

        constexpr Color operator*(const Color& other) const noexcept {
            return Color(clamp(m_r * other.m_r), clamp(m_g * other.m_g), clamp(m_b * other.m_b), clamp(m_a * other.m_a));
        }

        // --- Presets ---
        static constexpr Color White() noexcept { return Color(1, 1, 1, 1); }
        static constexpr Color Black() noexcept { return Color(0, 0, 0, 1); }
        static constexpr Color Red()   noexcept { return Color(1, 0, 0, 1); }
        static constexpr Color Green() noexcept { return Color(0, 1, 0, 1); }
        static constexpr Color Blue()  noexcept { return Color(0, 0, 1, 1); }
        static constexpr Color Transparent() noexcept { return Color(0, 0, 0, 0); }

        std::string toString() const {
            char buf[64];
            snprintf(buf, sizeof(buf), "Color(%.2f, %.2f, %.2f, %.2f)", m_r, m_g, m_b, m_a);
            return std::string(buf);
        }
    };

} // namespace retronomicon::graphics
