#pragma once

#include <memory>
#include "retronomicon/asset/image_asset.h"

namespace retronomicon::graphics {

    /**
     * @brief Backend-agnostic texture interface.
     *
     * Represents a 2D GPU texture created from an ImageAsset or other image source.
     * Rendering backends (SDL, OpenGL, Vulkan, etc.) must implement this interface
     * to expose:
     *  - pixel dimensions,
     *  - binding / unbinding operations,
     *  - any additional backend-specific handles internally.
     *
     * This class is intentionally minimal to keep frontend rendering code portable.
     */
    class Texture {
    public:
        virtual ~Texture() = default;

        /**
         * @brief Get the width of the texture in pixels.
         */
        virtual int getWidth() const = 0;

        /**
         * @brief Get the height of the texture in pixels.
         */
        virtual int getHeight() const = 0;

        /**
         * @brief Bind or activate the texture for rendering.
         *
         * Backends implement this differently:
         *  - **OpenGL**: `glBindTexture(GL_TEXTURE_2D, id)`
         *  - **SDL**: no-op (SDL manages binding internally)
         *  - **Vulkan/Metal**: typically handled via descriptor sets
         */
        virtual void bind() const = 0;

        /**
         * @brief Unbind or deactivate the texture.
         *
         * Many backends do not require this (`unbind()` may be a no-op),
         * but the method exists to keep the interface consistent.
         */
        virtual void unbind() const = 0;
    };

    /// Shared pointer alias for convenience.
    using TexturePtr = std::shared_ptr<Texture>;

} // namespace retronomicon::graphics
