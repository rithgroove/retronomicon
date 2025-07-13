#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "retronomicon/lib/asset/asset.h"

namespace retronomicon::lib::asset {

/**
 * @brief A class that represents a loaded font from storage to memory.
 *        Provides functionality to render text as textures.
 */
class FontAsset : public Asset {
public:
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

    /**
     * @brief Destructor: destroys the TTF_Font and releases resources
     */
    ~FontAsset() override;

    /**
     * @brief Returns whether the font was successfully loaded
     *
     * @return true if font is valid
     */
    bool isInitialized() const;

    /**
     * @brief Get the raw TTF_Font pointer
     *
     * @return pointer to TTF_Font
     */
    TTF_Font* getRawFont() const;

    /**
     * @brief Get the font size in points
     *
     * @return font size
     */
    int getFontSize() const;

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
     * @brief Return a debug description of this font asset
     */
    std::string to_string() const override;

private:
    SDL_Renderer* m_renderer = nullptr;
    int m_fontSize = 0;       // size in pt
    TTF_Font* m_font = nullptr;  // SDL_ttf loaded font
};

}
