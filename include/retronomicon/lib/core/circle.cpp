#include <string>
#include <SDL.h>
/**
 * The namespace for anything renderable that is not a screen.
 */
namespace retronomicon::lib::core{
	/**
	 * An abstract class to mark wether the object is renderable or not
	 *
	 */
    class Circle {
	    public:
	    	virtual ~Renderable() = default; // destructor
	    	virtual bool update() = 0; //update function (might change in the future)
	    	virtual bool render(SDL_Renderer* m_renderer) = 0; 
	    	void setPosition(int x, int y);//render function (might change in the future to include renderer)
	    	int getX();
	    	int getY();
	    	int getHeight();
	    	int getWidth();
	    	float getScale();
	    private:
	    	int m_x; // xrender position 
	    	int m_y; // y renderposition
	    	int m_width; // width of the object
	    	int m_height; // height of the object
	        float m_scale = 1.0;
    };
} // namespace Retronomicon