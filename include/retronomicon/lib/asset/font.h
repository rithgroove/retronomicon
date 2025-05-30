#pragma once

#include <SDL_ttf.h>
#include <string>
using namespace std;
/**
 * This namespace is for handling asset loading 
 */
namespace retronomicon::lib::asset{
    /**
     *  A class that represent a loaded font from storage to memory
     */    
	class Font {
		public:
		    Font(string filePath, string name, int fontSize); //Constructor: initialize the font (TTF_Font)	 
		    ~Font(); //Destructor: destroy the font (TTF_Font);

		    TTF_Font* getRawFont() const; // function to get the raw font (it's accesible, but not recommended for use)
            bool isInitialized() const; // check if font is initialized 
            string getName() ;
            string getPath() ;
            // SDL_Texture* generateTexture(const std::string& filePath); //generate texture from text using this font (might add size later)
		private:
            string m_fontPath;
            string m_name;
		    TTF_Font* m_font; // the loaded font
	};
}
