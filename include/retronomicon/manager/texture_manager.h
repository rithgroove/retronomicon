#pragma once

#include <memory>

#include "retronomicon/graphics/texture.h"
#include "retronomicon/asset/image_asset.h"
#include "retronomicon/asset/font_asset.h"

/**
 * @brief The namespace for ECS libraries that will be the building blocks for the engine
 */
namespace retronomicon::manager {

    using retronomicon::graphics::Texture;
    using retronomicon::asset::ImageAsset;
    using retronomicon::asset::FontAsset;

    /**
     * @brief Abstract texture creation interface.
     *
     * Concrete backends (OpenGL, SDL, Vulkan, etc.) override texture construction
     * from different asset types. This keeps the core clean and backend-agnostic.
     */
    class TextureManager {
    public:
        virtual ~TextureManager(); // must NOT be inline

        /**
         * @brief Create a backend texture from an ImageAsset.
         *        (Used by SpriteComponent)
         */
        virtual std::shared_ptr<Texture> createTexture(std::shared_ptr<ImageAsset> imageAsset);

        /**
         * @brief Create a backend texture from a FontAsset atlas.
         *        (Used by TextLabelComponent)
         *
         * Core does not know how the atlas is produced — backends fill
         * FontAsset glyph metrics + atlas data, then construct a Texture.
         */
        virtual std::shared_ptr<Texture> createTexture(std::shared_ptr<FontAsset> fontAsset);
    };

} // namespace retronomicon::manager
