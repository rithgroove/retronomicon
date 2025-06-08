#include <string>
#include <SDL.h>
#include <math.h>
#include "point.h"
/**
 * The namespace for basic libraries such as points, rectangle cirle, etc.
 */
using namespace retronomicon::lib::core;
namespace retronomicon::lib::core{
	/**
	 * A class that represent a single point
	 */
    class Point {
	    public:
	    	Rectangle(Point& position, int width, int height); //constructor position, width, and height
	    	Rectangle(Point& position, Point& anchor, int width, int height); //constructor position, anchor point, width, and height
	    	// ~Point(); // no need for destructor since all attributes are native
	    	void setSize(int width, int height);//render function (might change in the future to include renderer)
	    	void setPosition(int x, int y);
	    	void setPosition(Point& position);
	    	Point* getPosition(); 
	    	Point* getAnchor();
	    	int getWidth();
	    	int getHeight();
	    	int getX();
	    	int getY();

	    private:
	    	Point* m_anchor;
	    	Point* position;
	    	int m_width;
	    	int m_height;
    };
} // namespace Retronomicon