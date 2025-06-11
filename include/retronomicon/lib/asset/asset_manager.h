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

	        bool loadImage(const string& imagePath,const string& name);
	        RawImage* getImage(const string& name);
	        bool removeImage(const string& name);

	        bool loadFont(const string& fontPath, const string& name, int size);
	        Font* getFont(const string& name, int size);
	        bool removeFont(const string& name, int size);
	        

	    private:
	    	SDL_Renderer* m_renderer;
	    	unordered_map<string,RawImage*> m_imageMap{};
	    	unordered_map<string,Font*> m_fontMap;
    };
} // namespace Retronomicon