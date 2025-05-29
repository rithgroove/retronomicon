#include <iostream>
#include <unordered_map>
#include <string>
#include "font.h"
#include "retronomicon/lib/graphic/sprite.h"
#include "retronomicon/lib/asset/raw_image.h"
namespace retronomicon::lib::graphic::screen{
	/**
	 * A class that loads assets from storage and put in memory for ease of use
	 *
	 * To ensure faster access to assets. We wanted to load images, font, audio to this engine. 
	 *
	 */
    class Screen {
	    public:
	    	virtual ~Screen() = default;
	    	virtual bool update() = 0;
	    	virtual bool render() = 0;
	        
    };
} // namespace Retronomicon