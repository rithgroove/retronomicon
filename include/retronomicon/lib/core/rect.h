
#pragma once
#include <string>
#include <SDL.h>
#include <math.h>
#include "point.h"
/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
using namespace retronomicon::lib::core;
namespace retronomicon::lib::core{
	/**
	 * @brief A class that represent a rectangle
	 */
    class Rect {
	    public:
	    	/**
	    	* @brief constructor that accept 4 integer
	    	* also create anchor on top left. Point(0,0)
	    	* 
	    	* @param x the x position of this rectangle
	    	* @param y the y position of this rectangle
	    	* @param width the width this rectangle
	    	* @param height the height this rectangle
	    	*/
	    	Rect(int x, int y, int width, int height); 

	    	/**
	    	* @brief constructor with the position of this rectangle
	    	* also create anchor on top left. Point(0,0)
	    	* 
	    	* @param position the position int Point format
	    	* @param width the width this rectangle
	    	* @param height the height this rectangle
	    	*/
	    	Rect(Point* position, int width, int height); 


	    	/**
	    	* @brief constructor with the position of this rectangle
	    	* also create anchor on top left. Point(0,0)
	    	* 
	    	* @param position the position int Point format
	    	* @param anchor the anchor position of this rectangle
	    	* @param width the width this rectangle
	    	* @param height the height this rectangle
	    	*/
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