#pragma once
#include <string>
#include <SDL.h>
#include <math.h>
#include "retronomicon/lib/core/rect.h"
#include "retronomicon/lib/core/point.h"
#include "retronomicon/lib/asset/raw_image.h"

using namespace retronomicon::lib::asset;
using namespace retronomicon::lib::core;
/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::graphic::util{
	/**
	 * @brief A class that represent a frame in the animation sequence (the source image from sprite sheet)
	 */
    class Frame {
	    public:
	    	/**
	    	 * @brief basic constructor
	    	 * 
	    	 * @param x the x position of the start of the current frame from the spritesheet
	    	 * @param y the y position of the start of the current frame from the spritesheet
	    	 * @param width the width of the current frame from the spritesheet
	    	 * @param height the height of the current frame from the spritesheet
	    	 * @param rawImage the raw image (might remove it later, not used)
	    	 * @param sequence_order (a number to indicate which frame number this is)
	    	 * @param name the name of this frame
	    	 */
	    	Frame(int x, int y,int width, int height,RawImage* rawImage,int sequence_order, const string &name);

	    	/**
	    	 * @brief basic constructor
	    	 * 
	    	 * @param point the point representing the starting point of this frame
	    	 * @param width the width of the current frame from the spritesheet
	    	 * @param height the height of the current frame from the spritesheet
	    	 * @param rawImage the raw image (might remove it later, not used)
	    	 * @param sequence_order (a number to indicate which frame number this is)
	    	 * @param name the name of this frame
	    	 */
	    	Frame(Point* point,int width, int height,RawImage* rawImage,int sequence_order, const string &name);

	    	/**
	    	 * @brief basic constructor
	    	 * 
	    	 * @param rect the source rectangle of this frame
	    	 * @param rawImage the raw image (might remove it later, not used)
	    	 * @param sequence_order (a number to indicate which frame number this is)
	    	 * @param name the name of this frame
	    	 */
	    	Frame(Rect* rect,RawImage* rawImage,int sequence_order, const string &name); //constructor with 2 points (still considering wether we should use int or float or double)
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
	    	 * the rectangle representing the source rectangle of the sprite
	    	 * 
	    	 * @return the source rectangle
	    	 */
	    	Rect* getRect() const;
	    private:
	    	Rect* m_rect;
	    	RawImage* m_image;
	    	int m_sequence_order;
	    	string m_name;
    };
} // namespace Retronomicon