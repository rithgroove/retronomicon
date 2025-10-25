#pragma once
#include <memory>
#include "retronomicon/graphics/texture.h"
#include "retronomicon/asset/image_asset.h"  

/**
 * @brief The namespace for ECS libraries that will be the building blocks for the engine
 */
namespace retronomicon::manager {
    using retronomicon::graphics::Texture;
    using retronomicon::asset::ImageAsset;
    /**
     * @brief Generic class that traverses entities and calls render() on renderable components.
     */
    class TextureManager {
        public:
            virtual Texture createTexture(std::shared_ptr<ImageAsset> imageAsset);
    };

} // namespace retronomicon::manager
