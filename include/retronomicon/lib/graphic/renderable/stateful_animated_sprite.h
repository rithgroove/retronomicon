#pragma once

#include "sprite.h"
#include "retronomicon/lib/graphic/util/sequence_manager.h"

using namespace retronomicon::lib::asset;
using namespace retronomicon::lib::graphic::renderable;
using namespace std;
/**
 * @brief The namespace for anything renderable that is not a screen.
 */
namespace retronomicon::lib::graphic::renderable{
	/**
	 * A class for an animated sprite.
	 */
    class StatefulAnimatedSprite : public Sprite {
	    public:
	    	/**
	    	 * @brief a constructor for the Stateful animated sprite
	    	 * 
	    	 * @param rawImage the raw image generated by Asset Manager
	    	 * @param rect the rectangle tha represent the position of this sprite
	    	 * @param sequenceManager the sequenceManager
	    	 */
        	StatefulAnimatedSprite(RawImage* rawImage, Rect*rect, SequenceManager* sequenceManager); 
	    	// ~Sprite();

	    	/**
	    	 * @brief update function (might change in the future).
	    	 * Potential update is to use time interval so we could do frame skipping
	    	 * 
	    	 * @return true if successfull, false if failed
	    	 */
	    	bool update() override; //update function (might change in the future)
	    	
	    	/**
	    	 * @brief the method to render the objects
	    	 * 
	    	 * @parameter renderer the renderer the object will use
	    	 * @return true if successfull, false if failed
	    	 */
	    	bool render(SDL_Renderer* renderer) override; //render function (might change in the future to include renderer)
	    private:
	    	SequenceManager* m_sequenceManager;
    };
} // namespace Retronomicon