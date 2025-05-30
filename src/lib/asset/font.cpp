#include "retronomicon/lib/asset/font.h"
#include <iostream>
/**
 * This namespace is for handling asset loading 
 */
namespace retronomicon::lib::asset{
            
    /*************************************************************************************************
     * Constructor: initialize the font (TTF_Font)   
     *************************************************************************************************/
    Font::Font(string filePath, string name, int fontSize){
        //ttf init (might need to move it to load more than 1 font)
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
}