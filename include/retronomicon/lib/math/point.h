#pragma once

#include <string>
#include <ostream>
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
	    	constexpr Point() = default;

	    	/**
	    	 * @brief constructor with 2 points 	    	 
	    	 * 
	    	 * @param x the x position
	    	 * @param y the y position
	    	 */
	        constexpr Point(float x, float y) : m_x(x), m_y(y) {}
	    	

	    	/**
	    	 * @brief constructor with vec2
	    	 * 
	    	 * @param vector the 2D vector we want to convert to point
	    	 */
	        explicit Point(const Vec2& vector); // no accidental implicit conversions

	    	/***************************** Destructor *****************************/

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
	    	[[nodiscard]] constexpr float getX() const noexcept { return m_x; }
        
	    	/**
	    	 * @brief return the y position of the point
	    	 * 
	    	 * @return the y position of the point
	    	 */
	        [[nodiscard]] constexpr float getY() const noexcept { return m_y; }

	    	/***************************** Operator Overload *****************************/

	    	/**
		     * @brief overloading operator ==
		     * 
		     * @param other another point
		     */
	    	constexpr bool operator==(const Point& other) const noexcept;

    	    /**
		     * @brief overloading operator !=
		     * 
		     * @param other another point
		     */
			constexpr bool operator!=(const Point& other) const noexcept;

    	    /**
		     * @brief overloading operator +
		     * 
		     * @param other another point
		     */
			constexpr Point operator+(const Point& other) const noexcept;

    	    /**
		     * @brief overloading operator -
		     * 
		     * @param other another point
		     */
			constexpr Point operator-(const Point& other) const noexcept;

			/**
			 * @brief overloading operator << to call to_string()
			 */
			friend std::ostream& operator<<(std::ostream& os, const Point& obj) {
		        return os << obj.to_string();
		    }

	    	/***************************** To String *****************************/

	    	/**
	    	 * @brief a method to help people debug this object
	    	 * 
	    	 * @return Brief summary of this object in string
	    	 */
	    	[[nodiscard]] std::string to_string() const;

	    	/***************************** Main Methods *****************************/

	    	/**
	    	 * @brief calculate the distance between this point and target point
	    	 * 
	    	 * @param target the target point
	    	 * @return the distance in float
	    	 */
	    	[[nodiscard]] float calculateDistance(const Point& target) const noexcept;

	    	/***************************** Other Methods *****************************/

		    /**
		     * Convert point to Vec2
		     * 
		     * @return the vec2 representation of current point
		     */
    	    [[nodiscard]] Vec2 toVec2() const noexcept;
	    private:
            /***************************** Attribute *****************************/
	    	float m_x{0.0f}; // x position
	    	float m_y{0.0f}; // y position
    };
} // namespace Retronomicon