#include "retronomicon/asset/image_asset.h"
#include <stdexcept>
#include <sstream>

// stb_image implementation
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace retronomicon::asset {

    /***************************** Constructor *****************************/

    /**
     * @brief Constructor for the image asset
     *
     * @param imagePath the path to the image
    */
    ImageAsset::ImageAsset(const std::string& imagePath){
        : Asset(imagePath) // path + auto name
        // delegates to second constructor
    }

    /**
     * @brief Constructor for the image asset
     *
     * @param imagePath the path to the image
     * @param name the name of the image
     */
    ImageAsset::ImageAsset(const std::string& imagePath,
                           const std::string& name)
        : Asset(imagePath, name) 
    {
        m_path = imagePath;
        m_name = name;

        int width, height, channels;
        unsigned char* data = stbi_load(imagePath.c_str(), &width, &height, &channels, 4);
        // force 4 channels (RGBA), so every backend has consistent data

        if (!data) {
            throw std::runtime_error("Failed to load image: " + std::string(stbi_failure_reason()));
        }

        m_width = width;
        m_height = height;
        m_channels = 4; // because we forced RGBA
        m_pixels.assign(data, data + (width * height * 4));

        stbi_image_free(data); // free stb’s temp buffer
    }

    /***************************** Destructor *****************************/

    /**
     * @brief Destructor for the image asset
     *
     * Releases the SDL_Texture from memory
     */
    ImageAsset::~ImageAsset() {
        // nothing to cleanup, pixels live in std::vector
    }

    /***************************** To String *****************************/

    /**
     * @brief Return a textual description of the image asset
     *
     * @return debug string with name and path
     */
    std::string ImageAsset::to_string() const {
        std::ostringstream oss;
        oss << "[ImageAsset] " << m_name
            << " (" << m_width << "x" << m_height
            << ", channels=" << m_channels << ") from " << m_path;
        return oss.str();
    }

}
