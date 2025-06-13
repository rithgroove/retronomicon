#pragma once

#include <string>
#include <SDL.h>
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
	    	 * Notes : still considering wether we should use int or float or doubles
	    	 * 
	    	 * @param x the x position
	    	 * @param y the y position
	    	 */
	    	Point(int x, int y);
	    	
	    	// ~Point(); // no need for custom destructor (yet) since all attributes are native 

	    	/**
	    	 * @brief a function to change the position of the points
	    	 * 
	    	 * @param x the x position
	    	 * @param y the y position
	    	 */
	    	void set(int x, int y);

	    	/**
	    	 * @brief return the x position of the point
	    	 * 
	    	 * @return the x position of the point
	    	 */
	    	int getX() const; 

	    	/**
	    	 * @brief return the y position of the point
	    	 * 
	    	 * @return the y position of the point
	    	 */
	    	int getY() const;

	    	/**
	    	 * @brief calculate the distance between this point and target point
	    	 * 
	    	 * @param target the target point
	    	 * @return the distance in float
	    	 */
	    	float calculateDistance(Point* target);
	    private:
	    	int m_x; // x position
	    	int m_y; // y position
    };
} // namespace Retronomicon