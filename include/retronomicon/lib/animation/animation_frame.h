#pragma once

#include "retronomicon/lib/math/rect.h"

/**
 * @brief The namespace for animation utilities
 */
namespace retronomicon::lib::animation{
	/**
	 * @brief A class that represent a frame in the animation sequence (the source image from sprite sheet)
	 */
    class AnimationFrame {
	    public:
		    /***************************** Constructor *****************************/

	    	/**
	    	 * @brief basic constructor
	    	 * 
	    	 * @param x the x position of the start of the current frame from the spritesheet
	    	 * @param y the y position of the start of the current frame from the spritesheet
	    	 * @param width the width of the current frame from the spritesheet
	    	 * @param height the height of the current frame from the spritesheet
	    	 * @param duration in milisecond
	    	 */
	    	AnimationFrame(int x, int y,int width, int height, float duration) noexcept;

	    	/**
	    	 * @brief basic constructor
	    	 * 
	    	 * @param point the point representing the starting point of this frame
	    	 * @param width the width of the current frame from the spritesheet
	    	 * @param height the height of the current frame from the spritesheet
	    	 * @param duration in milisecond
	    	 */
		    AnimationFrame(const retronomicon::lib::math::Point& point, int width, int height, float duration) noexcept;
	    
	    	/**
	    	 * @brief basic constructor
	    	 * 
	    	 * @param rect the source rectangle of this frame
	    	 * @param duration in milisecond
	    	 */
    		AnimationFrame(const retronomicon::lib::math::Rect& rect, float duration) noexcept;

		    /***************************** Destructor *****************************/

   	    	// ~Point(); // no need for destructor since all attributes are native


		    /***************************** Getter *****************************/

	    	/**
	    	 * @brief get the x position of this frame
	    	 * 
	    	 * @return x position
	    	 */
	    	[[nodiscard]] int getX() const noexcept {return m_rect.getX();} // get X position
	    	
	    	/**
	    	 * @brief get the y position of this frame
	    	 * 
	    	 * @return y position
	    	 */
	    	 [[nodiscard]] int getY() const noexcept {return m_rect.getY();} // get Y position

	    	/**
	    	 * @brief get the width  of this frame
	    	 * 
	    	 * @return width
	    	 */
	    	[[nodiscard]] int getWidth() const noexcept {return m_rect.getWidth();} // get X position
	    	
	    	/**	    	 * @brief get height of this frame
	    	 * 
	    	 * @return height
	    	 */
	    	 [[nodiscard]] int getHeight() const noexcept {return m_rect.getHeight();} // get Y position

	    	/**
	    	 * the rectangle representing the source rectangle of the sprite
	    	 * 
	    	 * @return the source rectangle
	    	 */
	    	[[nodiscard]] retronomicon::lib::math::Rect getRect() const noexcept {return m_rect;}

		    /***************************** Utility *****************************/

	    	/**
	    	 * @brief a method to reset spent duration (set m_spentDuration to 0)
	    	 */
	    	void reset() noexcept { m_elapsedTime = 0.0f; }

	    	/***************************** Operator Overload *****************************/

            /**
             * @brief overloading operator << to call to_string()
             */
            friend std::ostream& operator<<(std::ostream& os, const AnimationFrame& obj) {
                return os << obj.to_string();
            }

	    	/***************************** To String *****************************/

	    	/**
	    	 * @brief a method to help people debug this object
	    	 * 
	    	 * @return Brief summary of this object in string
	    	 */
	    	[[nodiscard]] std::string to_string() const;

		    /***************************** Main Method *****************************/

	    	/**
	    	 * @brief update the frame to the next one
	    	 * 
	    	 * @return left over delta time
	    	 */
            float update(float dt);

	    private:
		    /***************************** Attribute *****************************/
	    	retronomicon::lib::math::Rect m_rect; //the rectangle
	    	float m_duration; // duration for this frame in ms
	    	float m_elapsedTime; //how many of the duration is spent currently
    };
} // namespace Retronomicon