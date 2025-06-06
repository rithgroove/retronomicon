#include "retronomicon/lib/asset/font.h"
#include <iostream>
/**
 * This namespace is for handling asset loading 
 */
namespace retronomicon::lib::graphic::renderable{
            
    /*************************************************************************************************
     * Constructor: initialize the font (TTF_Font)   
     *************************************************************************************************/
    Sprite::Sprite(RawImage image, int x, int y, SDL_Renderer* renderer){
        //ttf init (might need to move it to load more than 1 font)
        m_renderer = renderer;
        if (TTF_Init() == -1) {
            std::cerr << "TTF_Init failed: " << TTF_GetError() << std::endl;
            return;
        }

        // load the font
        m_font = TTF_OpenFont(filePath.c_str(), fontSize);
        if (!m_font) {
            std::cerr << "Failed to load font: " << filePath << ", Error: " << TTF_GetError() << std::endl;
        }

        m_name =name;
        m_fontPath = filePath;
    }


    /*************************************************************************************************
     * Destructor: remove the font
     *************************************************************************************************/
    Font::~Font() {
        if (m_font) {
            TTF_CloseFont(m_font);
            m_font = nullptr;
        }
        //TTF_Quit(); //might need this later
    }


    /*************************************************************************************************
     * check if font is initialized 
     *************************************************************************************************/
    bool Font::isInitialized() const{
        return m_font != NULL;
    }

    /*************************************************************************************************
     * function to get the raw font (it's accesible, but not recommended for use)
     *************************************************************************************************/
    TTF_Font* Font::getRawFont() const {
        return m_font;
    }

    /*************************************************************************************************
     * Get font name
     *************************************************************************************************/
    string Font::getName()  {
        return m_name;
    }

    /*************************************************************************************************
     * Get font file path
     *************************************************************************************************/
    string Font::getPath()  {
        return m_fontPath;
    }

    // SDL_Texture* renderText (retronomicon::lib::graphic::Font main_font,SDL_Renderer *ren, SDL_Surface* screen, char* string,int x, int y, SDL_Color fgC, SDL_Color bgC) {

    SDL_Texture* Font::generateTexture(const string text, int horizontalPadding, int verticalPadding,int width,  int height, SDL_Color fgC, SDL_Color bgC){
        TTF_SetFontStyle(m_font, TTF_STYLE_BOLD);
        SDL_Surface* textSurface = TTF_RenderText_Solid(m_font, text.c_str(), fgC);     // aliased glyphs
        // SDL_Surface* textSurface = TTF_RenderText_Shaded(main_font.getRawFont(), string, fgC, bgC);   // anti-aliased glyphs
        
        SDL_Surface* textBox = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_RGBA8888);
        if (!textBox) {
            SDL_Log("Failed to create surface: %s", SDL_GetError());
            return nullptr;
        }

        // Brown color in RGBA: RGB(139, 69, 19)
        // Uint32 brown = SDL_MapRGBA(surface->format, 139, 69, 19, 255);

        // Fill the entire surface with the brown color
        // SDL_FillRect(surface, nullptr, brown);
        
        SDL_Rect textLocation = { horizontalPadding, verticalPadding, 0, 0 };
        if (SDL_BlitSurface(textSurface, NULL, textBox, &textLocation) == 0){
            printf("\nsuccess to blit surface");
            fflush(stdout);
        }else{
            printf("\nfailed to blit surface");
            fflush(stdout);
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer,textBox);
        SDL_FreeSurface(textBox);
        return texture;
    }
}