#include "renderable.h"
#include "retronomicon/lib/asset/raw_image.h"
#include <SDL.h>
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
        	Sprite(RawImage* rawImage, int x, int y); //set texture and render position
	    	~Sprite() ;
	    	bool update(); //update function (might change in the future)
	    	bool render(SDL_Renderer* m_renderer); //render function (might change in the future to include renderer)
	    private:
	    	RawImage* m_rawImage;
	    	int m_x;
	    	int m_y;
	        SDL_Texture* m_texture = nullptr; // the texture
	        SDL_RendererFlip m_flip = SDL_FLIP_NONE; //the option is : SDL_FLIP_NONE,SDL_FLIP_HORIZONTAL,SDL_FLIP_VERTICAL

	        
    }
} // namespace Retronomicon