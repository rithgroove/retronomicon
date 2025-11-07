#pragma once

#include "retronomicon/graphics/texture.h"
#include "retronomicon/math/vec2.h"
#include "retronomicon/math/rect.h"
#include "retronomicon/graphics/color.h"

#include <memory>

namespace retronomicon::graphics::renderer {

using retronomicon::graphics::Texture;
using retronomicon::graphics::Color;
using retronomicon::math::Vec2;
using retronomicon::math::Rect;

/**
 * @brief Abstract interface for all rendering backends.
 *
 * Defines lifecycle and rendering responsibilities for any graphics API
 * (e.g., SDL, OpenGL, Vulkan). Implementations manage initialization,
 * drawing, and teardown of the rendering backend.
 */
class IRenderer {
public:
    virtual ~IRenderer() = default;

    // ------------------------------------------------------------
    // Lifecycle
    // ------------------------------------------------------------

    /**
     * @brief Initialize the renderer.
     */
    virtual void init() = 0;

    /**
     * @brief Clear the screen (usually called before drawing each frame).
     */
    virtual void clear() = 0;

    /**
     * @brief Present the rendered frame to the screen.
     */
    virtual void show() = 0;

    /**
     * @brief Shutdown and release resources.
     */
    virtual void shutdown() = 0;

    // ------------------------------------------------------------
    // Rendering
    // ------------------------------------------------------------

    /**
     * @brief Render a texture with position/scale (simple mode).
     *
     * @param texture Texture to render.
     * @param position Top-left position in world or screen space.
     * @param scale Scaling factors.
     * @param rotation Rotation in degrees (clockwise).
     * @param alpha Opacity (0.0f–1.0f).
     */
    virtual void render(std::shared_ptr<Texture> texture,
                        const Vec2& position,
                        const Vec2& scale,
                        float rotation = 0.0f,
                        float alpha = 1.0f) = 0;

    /**
     * @brief Render a textured quad with full control.
     *
     * This version allows specifying both source and destination rectangles,
     * rotation, alpha blending, and color tinting.
     *
     * @param texture Texture to render.
     * @param target  Target rectangle (screen position + size).
     * @param source  Source rectangle (portion of texture to draw).
     * @param rotation Rotation angle in degrees (around target center).
     * @param alpha    Opacity multiplier (0.0f = invisible, 1.0f = opaque).
     * @param color    RGBA tint color multiplier.
     */
    virtual void renderQuad(std::shared_ptr<Texture> texture,
                            const Rect& target,
                            const Rect& source,
                            float rotation = 0.0f,
                            float alpha = 1.0f,
                            const Color& color = Color::White()) = 0;

    // ------------------------------------------------------------
    // Utilities
    // ------------------------------------------------------------

    /**
     * @return The width of the render surface (e.g., window width).
     */
    virtual int getWidth() const = 0;

    /**
     * @return The height of the render surface (e.g., window height).
     */
    virtual int getHeight() const = 0;
};

} // namespace retronomicon::graphics::renderer
