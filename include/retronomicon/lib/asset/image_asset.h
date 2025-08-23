#pragma once

#include <SDL.h>
#include <string>
#include "asset.h"

/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::lib::asset {


    /***************************** Constructor *****************************/
    /**
     * @brief A class that represents a loaded image asset from storage into memory.
     *        Converts an image file into an SDL_Texture for rendering.
     */
    class ImageAsset : public Asset {
        public:

            /***************************** Constructor *****************************/
            
            /**
             * @brief Constructor for the image asset
             *
             * @param imagePath the path to the image
             * @param name the name of the image
             * @param renderer SDL_Renderer used to create texture from image
             */
            ImageAsset(const std::string& imagePath, const std::string& name, SDL_Renderer* renderer);

            /***************************** Destructor *****************************/

            /**
             * @brief Destructor for the image asset
             *
             * Releases the SDL_Texture from memory
             */
            ~ImageAsset() override;

            /***************************** Getter *****************************/
        
            /**
             * @brief Get the width of the image
             *
             * @return the width in pixels
             */
            int getWidth() const{ return m_width; }

            /**
             * @brief Get the height of the image
             *
             * @return the height in pixels
             */
            int getHeight() const{ return m_height; }

            /**
             * @brief Get the loaded SDL_Texture
             *
             * @return the image texture
             */
            SDL_Texture* getTexture() const{ return m_texture;}

            /***************************** To String *****************************/

            /**
             * @brief Return a textual description of the image asset
             *
             * @return debug string with name and path
             */
            std::string to_string() const override;

        private:

            /***************************** Attribute *****************************/
            SDL_Texture* m_texture = nullptr;  // The texture created from the image file
            int m_width = 0;                   // Width of the image
            int m_height = 0;                  // Height of the image
    };

}
