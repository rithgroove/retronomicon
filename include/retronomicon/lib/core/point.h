#pragma once

#include <math.h>

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::core{
	/**
	 * @brief A class that represent a single point
	 */
    class Point {
	    public:
	    	/**
	    	 * @brief constructor with 2 points 	    	 
	    	 * 
	    	 * @param x the x position
	    	 * @param y the y position
	    	 */
	    	Point(float x, float y);
	    	
	    	// ~Point(); // no need for custom destructor (yet) since all attributes are native 

	    	/**
	    	 * @brief a function to change the position of the points
	    	 * 
	    	 * @param x the x position
	    	 * @param y the y position
	    	 */
	    	void set(float x, float y);

	    	/**
	    	 * @brief return the x position of the point
	    	 * 
	    	 * @return the x position of the point
	    	 */
	    	float getX() const; 

	    	/**
	    	 * @brief return the y position of the point
	    	 * 
	    	 * @return the y position of the point
	    	 */
	    	float getY() const;

	    	/**
	    	 * @brief calculate the distance between this point and target point
	    	 * 
	    	 * @param target the target point
	    	 * @return the distance in float
	    	 */
	    	float calculateDistance(Point* target);
	    private:
	    	float m_x; // x position
	    	float m_y; // y position
    };
} // namespace Retronomicon