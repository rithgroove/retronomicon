#include <string>
#include <SDL.h>
#include <math.h>
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
	    	Point(int x, int y); //constructor with 2 points (still considering wether we should use int or float or double)
	    	// ~Point(); // no need for destructor since all attributes are native
	    	void set(int x, int y);//render function (might change in the future to include renderer)
	    	int getX(); // get X position
	    	int getY(); // get Y position
	    	float calculateDistance(Point target); // get float distance to a point 
	    private:
	    	int m_x; // x position
	    	int m_y; // y position
    };
} // namespace Retronomicon