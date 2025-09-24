#pragma once

#include <memory>
#include "retronomicon/asset/image_asset.h"

namespace retronomicon::graphics {

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
         * Implementation depends on backend (e.g., glBindTexture in OpenGL).
         */
        virtual void bind() const = 0;

        /**
         * @brief Unbind/deactivate the texture (optional depending on backend).
         */
        virtual void unbind() const = 0;
    };

    using TexturePtr = std::shared_ptr<Texture>;

} // namespace retronomicon::graphics
