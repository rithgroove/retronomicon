#pragma once

#include <SDL.h>
#include "point.h"

using namespace retronomicon::lib::math;

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::math{
	/**
	 * @brief A class that represent a rectangle
	 */
    class Rect {
	    public:
	    	/**
	    	* @brief constructor that accept 4 floating value
	    	* also create anchor on top left. Point(0,0)
	    	* 
	    	* @param x the x position of this rectangle
	    	* @param y the y position of this rectangle
	    	* @param width the width this rectangle
	    	* @param height the height this rectangle
	    	*/
	    	Rect(float x, float y, float width, float height); 

	    	/**
	    	* @brief constructor with the position of this rectangle
	    	* also create anchor on top left. Point(0,0)
	    	* 
	    	* @param position the position float Pofloat format
	    	* @param width the width this rectangle
	    	* @param height the height this rectangle
	    	*/
	    	Rect(Point* position, float width, float height); 


	    	/**
	    	* @brief constructor with the position of this rectangle
	    	* also create anchor on top left. Point(0,0)
	    	* 
	    	* @param position the position float Pofloat format
	    	* @param anchor the anchor position of this rectangle
	    	* @param width the width this rectangle
	    	* @param height the height this rectangle
	    	*/
	    	Rect(Point* position, Point* anchor, float width, float height); 


	    	// ~Rect(); // to do : dev 

	       /**
	    	* @brief a method to change the size of the rectangle
	    	* 
	    	* @param width the new width for this rectangle
	    	* @param height the new height for this rectangle
	    	*/
	    	void setSize(float width, float height);

	       /**
	    	* @brief a method to change the position of the rectangle
	    	* 
	    	* @param x the new x position for this rectangle
	    	* @param y the new y position for this rectangle
	    	*/
	    	void setPosition(float x, float y);

	    	/**
	    	 * @brief a method to change the position of the rectangle
	    	 * 
	    	 * @param position the new position in Point class
	    	 */
	    	void setPosition(Point* position);

	    	/**
	    	 * @brief a method to get the position of the rectangle
	    	 * 
	    	 * @return the position in point format
	    	 */
	    	Point* getPosition() const; 

	    	/**
	    	 * @brief a method to get the anchor position of the rectangle
	    	 * 
	    	 * @return the anchor position in point format
	    	 */
	    	Point* getAnchor() const;

	    	/**
	    	 * @brief a method to get the width of rectangle
	    	 * 
	    	 * @return the width of the rectangle
	    	 */
	    	float getWidth() const;

	    	/**
	    	 * @brief a method to get the height of rectangle
	    	 * 
	    	 * @return the height of the rectangle
	    	 */
	    	float getHeight() const;

	    	/**
	    	 * @brief a method to get the x position of this rectangle
	    	 * 
	    	 * @return the x position of the rectangle
	    	 */
	    	float getX() const;

	    	/**
	    	 * @brief a method to get the y position of this rectangle
	    	 * 
	    	 * @return the y position of the rectangle
	    	 */
	    	float getY() const;


	    	/**
	    	 * @brief a method to get SDL_Rect representation of this rectangle.
	    	 * Useful for rendering textures.
	    	 * 
	    	 * @return the SDL_Rect
	    	 */
	    	SDL_Rect generateSDLRect();

	    private:
	    	Point* m_anchor;
	    	Point* m_position;
	    	float m_width;
	    	float m_height;
    };
} // namespace Retronomicon