#pragma once
#include <cstdint>
#include <algorithm>
#include <string>

namespace retronomicon::graphics {

/**
 * @brief Lightweight RGBA color class used by all rendering backends.
 *
 * Stores color values in normalized floating-point format (`[0.0, 1.0]`),
 * making it backend-agnostic and safe for blending, tinting, and math
 * operations. Backends (SDL, OpenGL, Vulkan, etc.) may extend this class
 * and override `toArray()` or provide backend-native conversions.
 *
 * Features:
 *  - Construction using floats or 8-bit byte values.
 *  - Arithmetic operations such as scalar multiply and color multiply.
 *  - Common preset colors (White, Black, Red, etc.).
 *  - Safe clamping on all write operations.
 */
class Color {
protected:
    float m_r; ///< Red channel   (0.0–1.0)
    float m_g; ///< Green channel (0.0–1.0)
    float m_b; ///< Blue channel  (0.0–1.0)
    float m_a; ///< Alpha channel (0.0–1.0)

    /**
     * @brief Clamp a value to the normalized color range [0,1].
     */
    static float clamp(float v) noexcept {
        return v < 0.0f ? 0.0f : (v > 1.0f ? 1.0f : v);
    }

public:
    // --------------------------------------------------------
    // Constructors
    // --------------------------------------------------------

    /**
     * @brief Default to opaque white (1,1,1,1).
     */
    Color() noexcept
        : m_r(1.0f), m_g(1.0f), m_b(1.0f), m_a(1.0f) {}

    /**
     * @brief Construct from normalized float values.
     *
     * @param r Red   component in [0,1]
     * @param g Green component in [0,1]
     * @param b Blue  component in [0,1]
     * @param a Alpha component in [0,1]
     */
    Color(float r, float g, float b, float a = 1.0f) noexcept
        : m_r(clamp(r)), m_g(clamp(g)), m_b(clamp(b)), m_a(clamp(a)) {}

    /**
     * @brief Construct from byte-range color channels (0–255).
     *
     * @param r Red channel
     * @param g Green channel
     * @param b Blue channel
     * @param a Alpha channel
     */
    static Color fromBytes(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) noexcept {
        return Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
    }

    // --------------------------------------------------------
    // Accessors
    // --------------------------------------------------------

    /// @return Red component in normalized range.
    float r() const noexcept { return m_r; }

    /// @return Green component.
    float g() const noexcept { return m_g; }

    /// @return Blue component.
    float b() const noexcept { return m_b; }

    /// @return Alpha component.
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

    /**
     * @brief Return a new color with modified alpha.
     *
     * @param alpha New alpha value.
     */
    Color withAlpha(float alpha) const noexcept {
        return Color(m_r, m_g, m_b, alpha);
    }

    /**
     * @brief Multiply all channels by a scalar.
     *
     * Useful for dimming, light intensity, fade animations, etc.
     */
    Color operator*(float scalar) const noexcept {
        return Color(clamp(m_r * scalar), clamp(m_g * scalar),
                     clamp(m_b * scalar), clamp(m_a * scalar));
    }

    /**
     * @brief Multiply two colors component-wise.
     *
     * Commonly used for tinting, blending overlays, and lighting passes.
     */
    Color operator*(const Color& other) const noexcept {
        return Color(clamp(m_r * other.m_r), clamp(m_g * other.m_g),
                     clamp(m_b * other.m_b), clamp(m_a * other.m_a));
    }

    // --------------------------------------------------------
    // Preset Colors
    // --------------------------------------------------------

    static Color White()       noexcept { return Color(1, 1, 1, 1); }
    static Color Black()       noexcept { return Color(0, 0, 0, 1); }
    static Color Red()         noexcept { return Color(1, 0, 0, 1); }
    static Color Green()       noexcept { return Color(0, 1, 0, 1); }
    static Color Blue()        noexcept { return Color(0, 0, 1, 1); }
    static Color Transparent() noexcept { return Color(0, 0, 0, 0); }

    // --------------------------------------------------------
    // Backend / Native Interface
    // --------------------------------------------------------

    /**
     * @brief Convert to a 4-float array in RGBA order.
     *
     * Backends can override this for more optimized packing formats.
     *
     * @param out Output array of size 4.
     */
    virtual void toArray(float out[4]) const noexcept {
        out[0] = m_r;
        out[1] = m_g;
        out[2] = m_b;
        out[3] = m_a;
    }

    // --------------------------------------------------------
    // Debug utilities
    // --------------------------------------------------------

    /**
     * @brief String representation for logging/debug overlays.
     *
     * @return e.g. `"Color(0.50, 0.25, 0.75, 1.00)"`
     */
    std::string toString() const {
        char buf[64];
        snprintf(buf, sizeof(buf), "Color(%.2f, %.2f, %.2f, %.2f)",
                 m_r, m_g, m_b, m_a);
        return std::string(buf);
    }

    // --------------------------------------------------------
    // Polymorphic behavior
    // --------------------------------------------------------
    virtual ~Color() = default;
};

} // namespace retronomicon::graphics
