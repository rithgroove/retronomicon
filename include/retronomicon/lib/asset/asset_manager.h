#pragma once

#include <unordered_map>
#include <string>
#include <SDL.h>
#include "font.h"
#include "raw_image.h"

using namespace std;
using namespace retronomicon::lib::asset;
/**
 * @brief This namespace is for handling asset loading 
 */
namespace retronomicon::lib::asset{
	/**
	 * @brief A class that loads assets from storage and put in memory for ease of use. To ensure faster access to assets. We wanted to load images, font, audio to this engine. 
	 *
	 */
    class AssetManager {
	    public:
	    	/**
	    	 * @brief Constructor using renderer
	    	 * 
	    	 * @param renderer a renderer that will be passed to any object loaded by this asset manager.
	    	 */
	        AssetManager(SDL_Renderer* renderer);   	

	    	/**
	    	 * @brief The destructor of the object, used to destroy maps using unsorted_map.clear() function
	    	 */
	        ~AssetManager(); //Destructor destroys the maps

	        /**
	         * @brief A method to load image from drive and put it in local map (m_imageMap) 
	         * caveats:
	         * - Currently only accept PNG.
	         * - will return nullptr if not found 
	         * - will return nullptr if name exist but have different filepath
	         * - will load the image from drive if not exist
	         * - if exists in cache will use the one preloaded before
	         * 
	         * @param imagePath the path to the image
	         * @param name the name or key for the image so we can request it again in the future
	         * @param forceReplace set true if you want to load the image from the drive again
	         * @return the image
	         */
	        RawImage* loadImage(const string& imagePath,const string& name, bool forceReplace = false); 


	        /**
	         * @brief  A method to get the loaded image
	         *
	         * @param name the name/key for the image
	         * @return the instance of RawImage that represent the image
	         */
	        RawImage* getImage(const string& name);

	        /**
	         * @brief A method to remove the loaded image from memory
	         *
	         * @param name the name/key for the image
	         * @return return true if success, return false if failed
	         */
	        bool removeImage(const string& name); 

	        /**
	         * @brief A method to load font from drive and put it in local map (m_fontMap)
	         * caveats:
	         * - Currently only accept TTF.
	         * - each size needs to be initiated differently (so Arial 16 and Arial 18 will be initiated as 2 different font)
	         * - will return nullptr if not found 
	         * - will return nullptr if name exist but have different filepath
	         * - will load the front from drive if not exist
	         * - if exists in cache will use the one preloaded before
	         * 
	         * @param imagePath the path to the font
	         * @param name the name or key for the font so we can request it again in the future
	         * @param size the size for the font so we can request it again in the future
	         * @param forceReplace set true if you want to load the image from the drive again
	         * @return return true if success, return false if failed
	         */
	        Font* loadFont(const string& fontPath, const string& name, int size,bool forceReplace = false); 

	        /**
	         * @brief A method to get the font from memory
	         *
	         * @param name the name/key for the font
	         * @param size the size of the font
	         */
	        Font* getFont(const string& name, int size);

	        /**
	         * @brief A method to remove the loaded font from memory
	         *
	         * @param name the name/key for the font
	         * @param size the size of the font
	         * @return return true if success, return false if failed
	         */
	        bool removeFont(const string& name, int size); 
	        
	    private:
	    	SDL_Renderer* m_renderer; // the renderer to be passed to font and images
	    	unordered_map<string,RawImage*> m_imageMap{}; //map of name with loaded image (RawImage)
	    	unordered_map<string,Font*> m_fontMap; //map of font name (and size) with loaded font (the actual format is "{font_name}-{size}")
    };
} // namespace Retronomicon