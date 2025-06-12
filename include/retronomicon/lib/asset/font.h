#pragma once

#include <SDL.h>
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
		    Font(string filePath, string name, int fontSize,SDL_Renderer* renderer); //Constructor: initialize the font (TTF_Font)	 
		    ~Font(); //Destructor: destroy the font (TTF_Font);

		    TTF_Font* getRawFont() const; // function to get the raw font (it's accesible, but not recommended for use)
            bool isInitialized() const; // check if font is initialized 
            string getName() ; // get the name of the font
            string getPath() ; //get the path of the font
            int getFontSize(); //get the Font Size
            SDL_Texture* generateTexture(const string text, int horizontalPadding, int verticalPadding,int width, int height,SDL_Color fgC, SDL_Color bgC); //generate texture from text using this font (might add size later)
		private:
			SDL_Renderer* m_renderer;
            string m_fontPath; // path to file
            string m_name; // name of file
            int m_fontSize; // font size
		    TTF_Font* m_font; // the loaded font
	};
}
