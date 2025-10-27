#include "retronomicon/manager/texture_manager.h"
#include <iostream>
/**
 * @brief The namespace for ECS libraries that will be the building blocks for the engine
 */
namespace retronomicon::manager {

    TextureManager::~TextureManager() = default;
    
    std::shared_ptr<Texture> TextureManager::createTexture(std::shared_ptr<ImageAsset> image) {
        return nullptr; // or throw std::runtime_error("Not implemented");
    }
}