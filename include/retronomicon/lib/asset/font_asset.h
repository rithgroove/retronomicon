#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include "retronomicon/lib/asset/asset.h"

/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::lib::asset {

    /**
     * @brief A class that represents a loaded font from storage to memory.
     *        Provides functionality to render text as textures.
     */
    class FontAsset : public Asset {
        public:
            /***************************** Constructor *****************************/

            /**
             * @brief Constructor for the font asset
             *
             * @param filePath path to the TTF file
             * @param name the given name for this font
             * @param fontSize the size (in pt) of the font
             * @param renderer SDL_Renderer for texture generation
             */
            FontAsset(const std::string& filePath,
                      const std::string& name,
                      int fontSize,
                      SDL_Renderer* renderer);

            /***************************** Destructor *****************************/

            /**
             * @brief Destructor: destroys the TTF_Font and releases resources
             */
            ~FontAsset() override;

            /***************************** Getter *****************************/

            /**
             * @brief Returns whether the font was successfully loaded
             *
             * @return true if font is valid
             */
            bool isInitialized() const{ return m_font != nullptr;}

            /**
             * @brief Get the raw TTF_Font pointer
             *
             * @return pointer to TTF_Font
             */
            TTF_Font* getRawFont() const { return m_font;}

            /**
             * @brief Get the font size in points
             *
             * @return font size
             */
            int getFontSize() const {return m_fontSize;}

            /***************************** Main Methods *****************************/
            
            /**
             * @brief Generate a rendered texture from text
             *
             * @param text the string to render
             * @param horizontalPadding pixels of horizontal margin
             * @param verticalPadding pixels of vertical margin
             * @param width target texture width
             * @param height target texture height
             * @param fgC foreground color (text)
             * @param bgC background color (drop shadow - not used)
             * @return SDL_Texture containing the rendered text
             */
            SDL_Texture* generateTexture(const std::string& text,
                                         int horizontalPadding,
                                         int verticalPadding,
                                         int width,
                                         int height,
                                         SDL_Color fgC,
                                         SDL_Color bgC);


            /**
             * @brief Measure the pixel size of a string using this font.
             * 
             * @param text input text
             * @param w output width in pixels
             * @param h output height in pixels
             * @return true if successful
             */
            bool measureText(const std::string& text, int& w, int& h) const;

            /**
             * @brief Word-wrap text to fit within a maximum width.
             * 
             * @param text input text
             * @param maxWidth maximum line width in pixels
             * @return vector of lines after wrapping
             */
            std::vector<std::string> wrapText(const std::string& text, int maxWidth) const;


            /***************************** To string *****************************/

            /**
             * @brief Textual representation of this asset (for debugging / editor)
             *     
             * @return string representation
             */
            std::string to_string() const override;

        private:
            SDL_Renderer* m_renderer = nullptr;
            int m_fontSize = 0;       // size in pt
            TTF_Font* m_font = nullptr;  // SDL_ttf loaded font
    };

}
