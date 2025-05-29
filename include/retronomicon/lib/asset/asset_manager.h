#include <iostream>
#include <unordered_map>
#include <string>
#include "font.h"
#include "retronomicon/lib/graphic/sprite.h"
#include "retronomicon/lib/asset/raw_image.h"
namespace retronomicon::lib::asset{
	/**
	 * A class that loads assets from storage and put in memory for ease of use
	 *
	 * To ensure faster access to assets. We wanted to load images, font, audio to this engine. 
	 *
	 */
    class AssetManager {
	    public:
	        AssetManager(); //Constructor initialize the maps	    	
	        ~AssetManager(); //Destructor destroys the maps

	        bool loadImage( const std::string& name, const std::string& imagePath);
	        bool getImage(const std::string& name);
	        bool removeImage(const std::string& name);

	        bool loadFont( const std::string& name, const std::string& imagePath);
	        bool getFont(const std::string& name);
	        bool removeFont(const std::string& name);
	        

	    private:
	    	std::unordered_map<std::string,retronomicon::lib:graphic::Font> m_fontMap;
	    	std::unordered_map<std::string,retronomicon::lib:graphic:Font> m_fontFileNameMap;
	    	std::unordered_map<std::string,retronomicon::lib:graphic::RawImage> m_imageMap;
	    	std::unordered_map<std::string,retronomicon::lib:graphic::RawImage> m_imageFileNameMap;
    };
} // namespace Retronomicon