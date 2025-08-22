#include "retronomicon/lib/asset/font_asset.h"

#include <iostream>
#include <sstream>
#include <SDL.h>
#include <SDL_ttf.h>

/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::lib::asset {

    /***************************** Constructor *****************************/
    /**
     * @brief Constructor for the font asset
     *
     * @param filePath path to the font file
     * @param name a name/key for this font
     * @param fontSize the size of the font
     * @param renderer SDL renderer for generating texture from text
     */
    FontAsset::FontAsset(const std::string& filePath,
                         const std::string& name,
                         int fontSize,
                         SDL_Renderer* renderer)
        : m_fontSize(fontSize), m_renderer(renderer)
    {
        m_name = m_name;
        m_path = filePath;

        m_font = TTF_OpenFont(filePath.c_str(), fontSize);
        if (!m_font) {
            std::cerr << "Failed to load font: " << filePath
                      << ", Error: " << TTF_GetError() << std::endl;
        }
    }

    /***************************** Destructor *****************************/
    /**
     * @brief Destructor: destroys the loaded TTF_Font
     */
    FontAsset::~FontAsset() {
        if (m_font) {
            TTF_CloseFont(m_font);
            m_font = nullptr;
        }
    }

    /***************************** Main Methods *****************************/

    /**
     * @brief Generate an SDL_Texture for the given text
     *
     * @param text the text to render
     * @param horizontalPadding pixels of horizontal padding
     * @param verticalPadding pixels of vertical padding
     * @param width target texture width
     * @param height target texture height
     * @param fgC foreground color (text color)
     * @param bgC background color (not currently used)
     * @return generated SDL_Texture with rendered text
     */
    SDL_Texture* FontAsset::generateTexture(const std::string& text,
                                            int horizontalPadding,
                                            int verticalPadding,
                                            int width,
                                            int height,
                                            SDL_Color fgC,
                                            SDL_Color bgC)
    {
        if (!m_font) {
            SDL_Log("Font not loaded in generateTexture!");
            return nullptr;
        }

        TTF_SetFontStyle(m_font, TTF_STYLE_BOLD);

        // Render text to a surface
        SDL_Surface* textSurface = TTF_RenderText_Solid(m_font, text.c_str(), fgC);  // aliased glyphs
        if (!textSurface) {
            SDL_Log("Failed to render text: %s", TTF_GetError());
            return nullptr;
        }

        // Auto-size if width/height are zero
        if (width == 0) {
            width = textSurface->w + horizontalPadding * 2;
        }
        if (height == 0) {
            height = textSurface->h + verticalPadding * 2;
        }

        // Create target surface for text box
        SDL_Surface* textBox = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_RGBA8888);
        if (!textBox) {
            SDL_Log("Failed to create surface: %s", SDL_GetError());
            SDL_FreeSurface(textSurface);
            return nullptr;
        }

        if (!m_renderer) {
            SDL_Log("Renderer is null in generateTexture!");
            SDL_FreeSurface(textSurface);
            SDL_FreeSurface(textBox);
            return nullptr;
        }

        // Blit the text onto the text box
        SDL_Rect textLocation = { horizontalPadding, verticalPadding, textSurface->w, textSurface->h };
        if (SDL_BlitSurface(textSurface, nullptr, textBox, &textLocation) != 0) {
            SDL_Log("Failed to blit text: %s", SDL_GetError());
        }

        // Convert surface to texture
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, textBox);

        SDL_FreeSurface(textSurface);
        SDL_FreeSurface(textBox);

        if (!texture) {
            SDL_Log("Failed to create texture: %s", SDL_GetError());
            std::cout << "Texturenya gagal generated" << std::endl;
        }

        return texture;
    }

    /***************************** To String *****************************/
    
    /**
     * @brief Return a debug string representation of this font
     */
    std::string FontAsset::to_string() const {
        std::ostringstream oss;
        oss << "[FontAsset] " << m_name << " (" << m_fontSize << "pt) from " << m_path;
        return oss.str();
    }

}
