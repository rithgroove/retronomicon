#pragma once

#include <string>
#include <vector>
#include "asset.h"

/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::asset {


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
            */
            ImageAsset(const std::string& imagePath);

            /**
             * @brief Constructor for the image asset
             *
             * @param imagePath the path to the image
             * @param name the name of the image
             */
            ImageAsset(const std::string& imagePath, const std::string& name);

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
            int getHeight() const { return m_height; }

            /**
             * @brief Get the vector of unsigned_char pixels
             *
             * @return the image texture
             */
            const std::vector<unsigned char>& getPixels() const { return m_pixels; }
    
            /**
             * @brief Get the image channels 
             * - 1 Grayscale
             * - 3 RGB
             * - 4 RGBA
             *
             * @return the image channel;
             */
            int getChannels() const { return m_channels; }

            /***************************** To String *****************************/

            /**
             * @brief Return a textual description of the image asset
             *
             * @return debug string with name and path
             */
            std::string to_string() const override;

        private:

            /***************************** Attribute *****************************/
            std::vector<unsigned char> m_pixels;
            int m_width = 0;
            int m_height = 0;
            int m_channels = 0; // e.g. 3 = RGB, 4 = RGBA
    };

}
