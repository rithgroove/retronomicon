#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

using namespace std;
/**
 * @brief This namespace is for handling asset loading 
 */
namespace retronomicon::lib::asset{
    /**
     * @brief A class that represent a loaded font from storage to memory
     */    
	class Font {
		public:
			/**
			 * @brief a constructor for the font class
			 * 
			 * @param filePath path to the file
			 * @param the name given to this font
			 * @param fontSize the size of the font
			 * @param renderer the renderer used to generate texture 
			 */
		    Font(string filePath, string name, int fontSize,SDL_Renderer* renderer); 

		    /**
		     * Destructor: destroy the font (TTF_Font);
		     */
		    ~Font();

		    /**
		     * @brief a method to get the raw font
		     * 
		     * @return TTF_Font the raw font
		     */
		    TTF_Font* getRawFont() const; 
		    
		    /**
		     * @brief a method to check if font is initialized 
		     * 
		     * @return true if initialized
		     */
            bool isInitialized() const; 

            /**
             * @brief a method to get the given name to this font
             * 
             * @return the name in string format
             */
            string getName() ; 
            
            /**
             * @brief a method to get the file path of this font
             * 
             * @return the filepath in string format
             */
            string getPath() ;

            /**
             * @brief a method to get the font size of this font
             * 
             * @return the font size
             */
            int getFontSize(); 

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
            SDL_Texture* generateTexture(const string text, int horizontalPadding, int verticalPadding,int width, int height,SDL_Color fgC, SDL_Color bgC);
		private:
			SDL_Renderer* m_renderer;
            string m_fontPath; // path to file
            string m_name; // name of file
            int m_fontSize; // font size
		    TTF_Font* m_font; // the loaded font
	};
}
