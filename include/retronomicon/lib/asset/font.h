#pragma once

#include <SDL_ttf.h>
#include <string>

/**
 * This namespace is for handling asset loading 
 */
namespace retronomicon:lib:asset{
    /**
     *  A class that represent a loaded font from storage to memory
     */    
	class Font {
		public:
		    Font(const std::string& filePath, int fontSize); //Constructor: initialize the font (TTF_Font)	 
		    ~Font(); //Destructor: destroy the font (TTF_Font);

		    TTF_Font* getRawFont() const; // function to get the raw font (it's accesible, but not recommended for use)
            bool isInitialized() const; // check if font is initialized 
            // SDL_Texture* generateTexture(const std::string& filePath); //generate texture from text using this font (might add size later)
		private:
		    TTF_Font* m_font; // the loaded font
	};
}
