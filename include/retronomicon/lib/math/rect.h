#pragma once

// #include <SDL.h>
#include "point.h"


/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::math{
	/**
	 * @brief A class that represent a rectangle
	 */
    class Rect {
	    public:
	    	/***************************** Constructor *****************************/

	        /**
	    	* @brief Default constructor
	    	*/
	        constexpr Rect() = default;

	    	/**
	    	* @brief constructor that accept 4 floating value
	    	* also create anchor on top left. Point(0,0)
	    	* 
	    	* @param x the x position of this rectangle
	    	* @param y the y position of this rectangle
	    	* @param width the width this rectangle
	    	* @param height the height this rectangle
	    	*/
	    	constexpr Rect(float x, float y, float width, float height) noexcept
		        : m_position(x, y), m_anchor(0.0f, 0.0f), m_width(width), m_height(height) {}

	    	/**
	    	* @brief constructor with the position of this rectangle
	    	* also create anchor on top left. Point(0,0)
	    	* 
	    	* @param position the position float Pofloat format
	    	* @param width the width this rectangle
	    	* @param height the height this rectangle
	    	*/
	        Rect(const Point& position, float width, float height) noexcept
		        : m_position(position), m_anchor(0.0f, 0.0f), m_width(width), m_height(height) {}

	    	/**
	    	* @brief constructor with the position of this rectangle
	    	* also create anchor on top left. Point(0,0)
	    	* 
	    	* @param position the position float Pofloat format
	    	* @param anchor the anchor position of this rectangle
	    	* @param width the width this rectangle
	    	* @param height the height this rectangle
	    	*/
	        Rect(const Point& position, const Point& anchor, float width, float height) noexcept
        		: m_position(position), m_anchor(anchor), m_width(width), m_height(height) {}


	    	/***************************** Destructor *****************************/
	    	
	    	// ~Rect(); // not implemented yet

	    	/***************************** Setter *****************************/

 	       /**
	    	* @brief a method to change the size of the rectangle
	    	* 
	    	* @param width the new width for this rectangle
	    	* @param height the new height for this rectangle
	    	*/
			void setSize(float width, float height) noexcept { m_width = width; m_height = height; }

	       /**
	    	* @brief a method to change the position of the rectangle
	    	* 
	    	* @param x the new x position for this rectangle
	    	* @param y the new y position for this rectangle
	    	*/
			void setPosition(float x, float y) noexcept { m_position.set(x, y); }

	    	/**
	    	 * @brief a method to change the position of the rectangle
	    	 * 
	    	 * @param position the new position in Point class
	    	 */
			void setPosition(const Point& position) noexcept { m_position = position; }


	    	/***************************** Getter *****************************/

	    	/**
	    	 * @brief a method to get the position of the rectangle
	    	 * 
	    	 * @return the position in point format
	    	 */
			[[nodiscard]] constexpr Point getPosition() const noexcept { return m_position; }

	    	/**
	    	 * @brief a method to get the anchor position of the rectangle
	    	 * 
	    	 * @return the anchor position in point format
	    	 */
			[[nodiscard]] constexpr Point getAnchor() const noexcept { return m_anchor; }

	    	/**
	    	 * @brief a method to get the width of rectangle
	    	 * 
	    	 * @return the width of the rectangle
	    	 */
			[[nodiscard]] constexpr float getWidth() const noexcept { return m_width; }

	    	/**
	    	 * @brief a method to get the height of rectangle
	    	 * 
	    	 * @return the height of the rectangle
	    	 */
			[[nodiscard]] constexpr float getHeight() const noexcept { return m_height; }

	    	/**
	    	 * @brief a method to get the x position of this rectangle
	    	 * 
	    	 * @return the x position of the rectangle
	    	 */
			[[nodiscard]] constexpr float getX() const noexcept { return m_position.getX(); }

	    	/**
	    	 * @brief a method to get the y position of this rectangle
	    	 * 
	    	 * @return the y position of the rectangle
	    	 */
			[[nodiscard]] constexpr float getY() const noexcept { return m_position.getY(); }

	    	/***************************** Operator Overload *****************************/

			/**
			 * @brief overloading operator << to call to_string()
			 */
			friend std::ostream& operator<<(std::ostream& os, const Rect& obj) {
		        return os << obj.to_string();
		    }

	    	/***************************** To String *****************************/

	    	/**
	    	 * @brief a method to help people debug this object
	    	 * 
	    	 * @return Brief summary of this object in string
	    	 */
	    	[[nodiscard]] std::string to_string() const;

	    private:
            /***************************** Attribute *****************************/            
	    	Point m_anchor{0.5f,0.5f};
	    	Point m_position{0.0f,0.0f};
	    	float m_width{0.0f};
	    	float m_height{0.0f};
    };
} // namespace Retronomicon