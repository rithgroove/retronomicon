#pragma once
#include <cstdint>
#include <algorithm>
#include <string>

namespace retronomicon::graphics {

/**
 * @brief Core RGBA color representation (engine-agnostic).
 *
 * This serves as the base color class for all rendering backends.
 * It stores floating-point color values in normalized [0,1] range,
 * and provides basic arithmetic and blending utilities.
 *
 * Derived classes (e.g. OpenGLColor, SDLColor) can override toNative()
 * to expose their platform-specific representation directly.
 */
class Color {
protected:
    float m_r;
    float m_g;
    float m_b;
    float m_a;

    static  float clamp(float v) noexcept {
        return v < 0.0f ? 0.0f : (v > 1.0f ? 1.0f : v);
    }

public:
    // --------------------------------------------------------
    // Constructors
    // --------------------------------------------------------
     Color() noexcept
        : m_r(1.0f), m_g(1.0f), m_b(1.0f), m_a(1.0f) {}

     Color(float r, float g, float b, float a = 1.0f) noexcept
        : m_r(clamp(r)), m_g(clamp(g)), m_b(clamp(b)), m_a(clamp(a)) {}

    static  Color fromBytes(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) noexcept {
        return Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
    }

    // --------------------------------------------------------
    // Accessors
    // --------------------------------------------------------
     float r() const noexcept { return m_r; }
     float g() const noexcept { return m_g; }
     float b() const noexcept { return m_b; }
     float a() const noexcept { return m_a; }

    // --------------------------------------------------------
    // Mutators
    // --------------------------------------------------------
     void setR(float r) noexcept { m_r = clamp(r); }
     void setG(float g) noexcept { m_g = clamp(g); }
     void setB(float b) noexcept { m_b = clamp(b); }
     void setA(float a) noexcept { m_a = clamp(a); }

    // --------------------------------------------------------
    // Operations
    // --------------------------------------------------------
     Color withAlpha(float alpha) const noexcept {
        return Color(m_r, m_g, m_b, alpha);
    }

     Color operator*(float scalar) const noexcept {
        return Color(clamp(m_r * scalar), clamp(m_g * scalar),
                     clamp(m_b * scalar), clamp(m_a * scalar));
    }

     Color operator*(const Color& other) const noexcept {
        return Color(clamp(m_r * other.m_r), clamp(m_g * other.m_g),
                     clamp(m_b * other.m_b), clamp(m_a * other.m_a));
    }

    // --------------------------------------------------------
    // Preset Colors
    // --------------------------------------------------------
    static  Color White() noexcept { return Color(1, 1, 1, 1); }
    static  Color Black() noexcept { return Color(0, 0, 0, 1); }
    static  Color Red()   noexcept { return Color(1, 0, 0, 1); }
    static  Color Green() noexcept { return Color(0, 1, 0, 1); }
    static  Color Blue()  noexcept { return Color(0, 0, 1, 1); }
    static  Color Transparent() noexcept { return Color(0, 0, 0, 0); }

    // --------------------------------------------------------
    // Virtual native interface
    // --------------------------------------------------------


    /**
     * @brief Converts the color to a 4-float array (RGBA order).
     */
    virtual void toArray(float out[4]) const noexcept {
        out[0] = m_r;
        out[1] = m_g;
        out[2] = m_b;
        out[3] = m_a;
    }

    // --------------------------------------------------------
    // Debug utility
    // --------------------------------------------------------
    std::string toString() const {
        char buf[64];
        snprintf(buf, sizeof(buf), "Color(%.2f, %.2f, %.2f, %.2f)", m_r, m_g, m_b, m_a);
        return std::string(buf);
    }

    // --------------------------------------------------------
    // Polymorphic behavior
    // --------------------------------------------------------
    virtual ~Color() = default;
};

} // namespace retronomicon::graphics
