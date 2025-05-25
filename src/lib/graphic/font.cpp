#include "retronomicon/lib/graphic/font.h"
#include <iostream>

namespace retronomicon {
    namespace lib{
        namespace graphic{
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

            Font::~Font() {
                if (m_font) {
                    TTF_CloseFont(m_font);
                }
                TTF_Quit();
            }

            bool Font::isInitialized() const{
                return m_font != NULL;
            }

            TTF_Font* Font::getRawFont() const {
                return m_font;
            }
        }
    }
}