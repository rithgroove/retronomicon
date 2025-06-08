
#pragma once
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
    class Rect {
	    public:
	    	Rect(int x, int y, int width, int height); //constructor position, width, and height
	    	Rect(Point* position, int width, int height); //constructor position, width, and height
	    	Rect(Point* position, Point* anchor, int width, int height); //constructor position, anchor point, width, and height
	    	// ~Point(); // no need for destructor since all attributes are native
	    	void setSize(int width, int height);//render function (might change in the future to include renderer)
	    	void setPosition(int x, int y);
	    	void setPosition(Point* position);
	    	Point* getPosition() const; 
	    	Point* getAnchor() const;
	    	int getWidth() const;
	    	int getHeight() const;
	    	int getX() const;
	    	int getY() const;
	    	SDL_Rect generateSDLRect();

	    private:
	    	Point* m_anchor;
	    	Point* m_position;
	    	int m_width;
	    	int m_height;
    };
} // namespace Retronomicon