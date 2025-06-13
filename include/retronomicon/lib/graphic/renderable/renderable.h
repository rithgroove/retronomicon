#pragma once
#include <string>
#include <SDL.h>
/**
 * @brief The namespace for anything renderable that is not a screen.
 */
namespace retronomicon::lib::graphic::renderable{
	/**
	 * @brief An abstract class to mark wether the object is renderable or not
	 *
	 */
    class Renderable {
	    public:
	    	/**
	    	 * @brief update function (might change in the future).
	    	 * Potential update is to use time interval so we could do frame skipping
	    	 * 
	    	 * @return true if successfull, false if failed
	    	 */
	    	virtual bool update() = 0; 

	    	/**
	    	 * @brief the method to render the objects
	    	 * 
	    	 * @parameter renderer the renderer the object will use
	    	 * @return true if successfull, false if failed
	    	 */
	    	virtual bool render(SDL_Renderer* renderer) = 0; 

    };
}