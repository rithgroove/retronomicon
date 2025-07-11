#pragma once

#include "retronomicon/lib/math/rect.h"

/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::animation{
	/**
	 * @brief A class that represent a frame in the animation sequence (the source image from sprite sheet)
	 */
    class AnimationFrame {
	    public:
	    	/**
	    	 * @brief basic constructor
	    	 * 
	    	 * @param x the x position of the start of the current frame from the spritesheet
	    	 * @param y the y position of the start of the current frame from the spritesheet
	    	 * @param width the width of the current frame from the spritesheet
	    	 * @param height the height of the current frame from the spritesheet
	    	 * @param duration in milisecond
	    	 */
	    	AnimationFrame(int x, int y,int width, int height, float duration);

	    	/**
	    	 * @brief basic constructor
	    	 * 
	    	 * @param point the point representing the starting point of this frame
	    	 * @param width the width of the current frame from the spritesheet
	    	 * @param height the height of the current frame from the spritesheet
	    	 * @param duration in milisecond
	    	 */
	    	AnimationFrame(retronomicon::lib::math::Point* point,int width, int height, float duration);

	    	/**
	    	 * @brief basic constructor
	    	 * 
	    	 * @param rect the source rectangle of this frame
	    	 * @param sequence_order (a number to indicate which frame number this is)
	    	 * @param name the name of this frame
	    	 * @param duration in milisecond
	    	 */
	    	AnimationFrame(retronomicon::lib::math::Rect* rect, float duration); //constructor with 2 points (still considering wether we should use int or float or double)
	    	// ~Point(); // no need for destructor since all attributes are native

	    	/**
	    	 * @brief get the x position of this frame
	    	 * 
	    	 * @return x position
	    	 */
	    	int getX() const; // get X position
	    	
	    	/**
	    	 * @brief get the y position of this frame
	    	 * 
	    	 * @return y position
	    	 */
	    	 int getY() const; // get Y position

	    	/**
	    	 * @brief get the width  of this frame
	    	 * 
	    	 * @return width
	    	 */
	    	int getWidth() const; // get X position
	    	
	    	/**	    	 * @brief get height of this frame
	    	 * 
	    	 * @return height
	    	 */
	    	 int getHeight() const; // get Y position

	    	/**
	    	 * the rectangle representing the source rectangle of the sprite
	    	 * 
	    	 * @return the source rectangle
	    	 */
	    	retronomicon::lib::math::Rect* getRect() const;

	    	/**
	    	 * @brief a method to reset spent duration (set m_spentDuration to 0)
	    	 */
	    	void reset();

	    	/**
	    	 * @brief update the frame to the next one
	    	 * 
	    	 * @return left over delta time
	    	 */
            float update(float dt);

	    private:
	    	retronomicon::lib::math::Rect m_rect; //the rectangle
	    	float m_duration; // duration for this frame in ms
	    	float m_elapsedTime; //how many of the duration is spent currently
    };
} // namespace Retronomicon