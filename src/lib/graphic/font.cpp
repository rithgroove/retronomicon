#include "retronomicon/lib/graphic/font.h"
#include <iostream>

namespace retronomicon:lib:graphic{
            
    Font::Font(const std::string& filePath, int fontSize) : m_font(nullptr) {
        if (TTF_Init() == -1) {
            std::cerr << "TTF_Init failed: " << TTF_GetError() << std::endl;
            return;
        }

        m_font = TTF_OpenFont(filePath.c_str(), fontSize);
        if (!m_font) {
            std::cerr << "Failed to load font: " << filePath << ", Error: " << TTF_GetError() << std::endl;
            fflush(stdout);
        }
    }

    // Font::~Font() {
    //     std::cout << "destroying font\n";
    //     fflush(stdout);
    //     if (m_font) {
    //         std::cout << "masuk if\n";
    //         fflush(stdout);
    //         TTF_CloseFont(m_font);
    //     }
    //     std::cout << "destroying font complete";
    //     fflush(stdout);
    //     TTF_Quit();
    //     std::cout << "ttf quit complete";
    //     fflush(stdout);
    // }

    bool Font::isInitialized() const{
        return m_font != NULL;
    }

    TTF_Font* Font::getRawFont() const {
        return m_font;
    }
}