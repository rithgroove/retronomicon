#include "retronomicon/lib/asset/image_asset.h"
#include <SDL_image.h>
#include <stdexcept>
#include <sstream>

namespace retronomicon::lib::asset {

    /**
     * @brief Constructor for the image asset
     * 
     * @param imagePath the path to the image
     * @param name the name of the image
     * @param renderer used to generate texture from the surface (image files -> SDL_Surface -> SDL_Texture)
     */
    ImageAsset::ImageAsset(const std::string& imagePath,
                           const std::string& name,
                           SDL_Renderer* renderer)
    {
        m_path = imagePath;
        m_name = name;

        // Load image to memory for CPU use
        SDL_Surface* surface = IMG_Load(imagePath.c_str());
        if (!surface) {
            throw std::runtime_error("Failed to load image: " + std::string(IMG_GetError()));
        }

        // Move from CPU surface to GPU texture
        m_texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!m_texture) {
            SDL_FreeSurface(surface);
            throw std::runtime_error("Failed to create texture: " + std::string(SDL_GetError()));
        }

        // Store width and height
        m_width = surface->w;
        m_height = surface->h;

        SDL_FreeSurface(surface); // Free the CPU surface
    }

    /**
     * @brief Destructor of the image asset
     * 
     * Releases the SDL texture to free GPU memory
     */
    ImageAsset::~ImageAsset() {
        if (m_texture) {
            SDL_DestroyTexture(m_texture);
            m_texture = nullptr;
        }
    }

    /**
     * @brief Get the loaded texture
     * 
     * @return the image in texture format
     */
    SDL_Texture* ImageAsset::getTexture() const {
        return m_texture;
    }

    /**
     * @brief Get the width of the image 
     * 
     * @return the image width
     */
    int ImageAsset::getWidth() const {
        return m_width;
    }

    /**
     * @brief Get the height of the image 
     * 
     * @return the image height
     */
    int ImageAsset::getHeight() const {
        return m_height;
    }

    /**
     * @brief Return a debug description of this image
     */
    std::string ImageAsset::to_string() const {
        std::ostringstream oss;
        oss << "[ImageAsset] " << m_name
            << " (" << m_width << "x" << m_height << ") from " << m_path;
        return oss.str();
    }

}
