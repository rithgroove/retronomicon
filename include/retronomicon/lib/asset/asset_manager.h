#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <SDL.h>
#include "font.h"
#include "raw_image.h"

using namespace std;
using namespace retronomicon::lib::asset;
namespace retronomicon::lib::asset{
	/**
	 * A class that loads assets from storage and put in memory for ease of use
	 *
	 * To ensure faster access to assets. We wanted to load images, font, audio to this engine. 
	 *
	 */
    class AssetManager {
	    public:
	        AssetManager(SDL_Renderer* m_renderer); //Constructor initialize the maps	    	
	        ~AssetManager(); //Destructor destroys the maps

	        bool loadImage(const string& imagePath,const string& name); //load image to memory. 
	        RawImage* getImage(const string& name); // get image from memory
	        bool removeImage(const string& name); // remove image from memory (destroy it)

	        bool loadFont(const string& fontPath, const string& name, int size); //load font to memory
	        Font* getFont(const string& name, int size); // get font from memory
	        bool removeFont(const string& name, int size); // remove font from memory
	        

	    private:
	    	SDL_Renderer* m_renderer; // the renderer to be passed to font and images
	    	unordered_map<string,RawImage*> m_imageMap{}; //map of name with loaded image (RawImage)
	    	unordered_map<string,Font*> m_fontMap; //map of font name (and size) with loaded font (the actual format is "{font_name}-{size}")
    };
} // namespace Retronomicon