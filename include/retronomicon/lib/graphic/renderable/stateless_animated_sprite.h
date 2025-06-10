#pragma once
#include "sprite.h"
#include "retronomicon/lib/asset/raw_image.h"
#include <SDL.h>
#include "retronomicon/lib/graphic/util/sequence.h"
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
    class StatelessAnimatedSprite : public Sprite {
	    public:
        	StatelessAnimatedSprite(RawImage* rawImage, Rect*rect, Sequence* sequence); //set texture and render position
	    	// ~Sprite();
	    	bool update() override; //update function (might change in the future)
	    	bool render(SDL_Renderer* m_renderer) override; //render function (might change in the future to include renderer)
	    private:
	    	Sequence* m_sequence;
    };
} // namespace Retronomicon