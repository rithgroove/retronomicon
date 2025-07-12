#pragma once

#include <cmath>
#include "vec2.h"

/**
 * @brief The namespace for basic math libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::math{
	/**
	 * @brief A class that represent a single point
	 */
    class Point {
	    public:
	    	/***************************** Constructor *****************************/

	    	/**
	    	 *  @brief default constructor with x=0 and y =0
	    	 */
	    	Point();

	    	/**
	    	 * @brief constructor with 2 points 	    	 
	    	 * 
	    	 * @param x the x position
	    	 * @param y the y position
	    	 */
	    	Point(float x, float y);
	    	
	    	// ~Point(); // no need for custom destructor (yet) since all attributes are native 

	    	/***************************** Setter *****************************/

	    	/**
	    	 * @brief a function to change the position of the points
	    	 * 
	    	 * @param x the x position
	    	 * @param y the y position
	    	 */
			void set(float x, float y) { m_x = x; m_y = y; }


	    	/***************************** Getter *****************************/
	    	/**
	    	 * @brief return the x position of the point
	    	 * 
	    	 * @return the x position of the point
	    	 */
	    	float getX() const { return m_x; }

	    	/**
	    	 * @brief return the y position of the point
	    	 * 
	    	 * @return the y position of the point
	    	 */
	    	float getY() const { return m_y; }

	    	/***************************** Operator Overload *****************************/

	    	/**
		     * @brief overloading operator ==
		     * 
		     * @param other another point
		     */
	    	bool operator==(const Point& other) const;

    	    /**
		     * @brief overloading operator !=
		     * 
		     * @param other another point
		     */
			bool operator!=(const Point& other) const;

    	    /**
		     * @brief overloading operator +
		     * 
		     * @param other another point
		     */
			Point operator+(const Point& other) const;

    	    /**
		     * @brief overloading operator -
		     * 
		     * @param other another point
		     */
			Point operator-(const Point& other) const;


	    	/***************************** Other Function *****************************/

	    	/**
	    	 * @brief calculate the distance between this point and target point
	    	 * 
	    	 * @param target the target point
	    	 * @return the distance in float
	    	 */
	    	float calculateDistance(const Point& target) const;

		    /**
		     * Convert point to Vec2
		     * 
		     * @return the vec2 representation of current point
		     */
    	    Vec2 toVec2() const;
	    private:
	    	float m_x; // x position
	    	float m_y; // y position
    };
} // namespace Retronomicon