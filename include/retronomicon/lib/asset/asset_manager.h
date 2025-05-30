#include <iostream>
#include <unordered_map>
#include <string>
#include <SDL.h>
// #include "font.h"
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
	        // ~AssetManager(); //Destructor destroys the maps

	        bool loadImage(const string& imagePath,const string& name);
	        RawImage* getImage(const string& name);
	        bool removeImage(const string& name);

	        // bool loadFont( const std::string& name, const std::string& imagePath);
	        // bool getFont(const std::string& name);
	        // bool removeFont(const std::string& name);
	        

	    private:
	    	// std::unordered_map<std::string,retronomicon::lib:graphic::Font> m_fontMap;
	    	// std::unordered_map<std::string,retronomicon::lib:graphic:Font> m_fontFileNameMap;
	    	SDL_Renderer* m_renderer;
	    	unordered_map<std::string,RawImage*> m_imageMap{};
	    	unordered_map<std::string,RawImage*> m_imageFileNameMap{};
    };
} // namespace Retronomicon