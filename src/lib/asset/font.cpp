#include "retronomicon/lib/asset/font.h"
/**
 * @brief This namespace is for handling asset loading 
 */
namespace retronomicon::lib::asset{
            
    /**
     * @brief a constructor for the font class
     * 
     * @param filePath path to the file
     * @param the name given to this font
     * @param fontSize the size of the font
     * @param renderer the renderer used to generate texture 
     */
    Font::Font(string filePath, string name, int fontSize,SDL_Renderer* renderer){
        //ttf init (might need to move it to load more than 1 font)
        m_renderer = renderer;

        // load the font
        m_font = TTF_OpenFont(filePath.c_str(), fontSize);
        if (!m_font) {
            std::cerr << "Failed to load font: " << filePath << ", Error: " << TTF_GetError() << std::endl;
        }

        m_name =name;
        m_fontPath = filePath;
        m_fontSize = fontSize;
    }

    /**
     * Destructor: destroy the font (TTF_Font);
     */
    Font::~Font() {
        if (m_font) {
            TTF_CloseFont(m_font);
            m_font = nullptr;
        }
    }

    /**
     * @brief a method to get the raw font
     * 
     * @return TTF_Font the raw font
     */
    bool Font::isInitialized() const{
        return m_font != NULL;
    }

    /**
     * @brief a method to check if font is initialized 
     * 
     * @return true if initialized
     */
    TTF_Font* Font::getRawFont() const {
        return m_font;
    }

    /**
     * @brief a method to get the given name to this font
     * 
     * @return the name in string format
     */
    string Font::getName()  {
        return m_name;
    }
        
    /**
     * @brief a method to get the file path of this font
     * 
     * @return the filepath in string format
     */
    string Font::getPath()  {
        return m_fontPath;
    }

    /**
     * @brief a method to get the font size of this font
     * 
     * @return the font size
     */
    int Font::getFontSize()  {
        return m_fontSize;
    }
    
    /**
     * @brief a method to generate texture so we could put it in renderer
     * 
     * @param text the text we wanted to render
     * @param horizontalPadding the horizontal padding for this text
     * @param verticalPadding for this text
     * @param width of the texture
     * @param height of the texture
     * @param foreground color 
     * @param background color (drop shadow) // not used at current moment
     * @return SDL_Texture the texture where the text is rendered
     */
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
        SDL_FreeSurface(textSurface);
        SDL_FreeSurface(textBox);
        return texture;
    }
}