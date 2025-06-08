#pragma once
#include "renderable.h"
#include "retronomicon/lib/asset/raw_image.h"
#include <SDL.h>
#include "retronomicon/lib/core/point.h"
#include "retronomicon/lib/core/rect.h"
using namespace retronomicon::lib::asset;
using namespace retronomicon::lib::graphic::renderable;
using namespace std;
/**
 * The namespace for anything renderable that is not a screen.
 */
namespace retronomicon::lib::graphic::renderable{
	/**
	 * A class for a static sprite.
	 */
    class Sprite : public Renderable {
	    public:
        	Sprite(RawImage* rawImage, Rect* rect); //set texture and render position
	    	// ~Sprite();
	    	bool update() override; //update function (might change in the future)
	    	bool render(SDL_Renderer* m_renderer) override; //render function (might change in the future to include renderer)
	    	bool getFlip();
	    	bool flip();
	    private:
	    	RawImage* m_rawImage;
	    	Rect* m_rect;   
	    	bool m_flip; // true = facing right
    };
} // namespace Retronomicon