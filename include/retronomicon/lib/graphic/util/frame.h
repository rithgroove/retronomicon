#pragma once
#include <string>
#include <SDL.h>
#include <math.h>
/**
 * The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::graphic::util{
	/**
	 * A class that represent a frame
	 */
    class Frame {
	    public:
	    	Frame(int x, int y,int width, int height,RawImage* rawImage,int sequence_order, string &name);
	    	Frame(Point* point,int width, int height,RawImage* rawImage,int sequence_order, string &name);
	    	Frame(Rect* rect,RawImage* rawImage,int sequence_order, string &name); //constructor with 2 points (still considering wether we should use int or float or double)
	    	// ~Point(); // no need for destructor since all attributes are native
	    	void set(int x, int y);//render function (might change in the future to include renderer)
	    	int getX() const; // get X position
	    	int getY() const; // get Y position
	    	float calculateDistance(Point* target);
	    private:
	    	Rect* m_rect;
	    	int sequence_order;
	    	string name;
    };
} // namespace Retronomicon