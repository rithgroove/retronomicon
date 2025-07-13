#include "retronomicon/lib/math/rect.h"

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::math{
    
    /***************************** Constructor *****************************/

    /**
    * @brief Default constructor all value is 0.0
    */
    Rect::Rect()
        : m_position(0.0f, 0.0f), m_anchor(0.0f, 0.0f), m_width(0.0f), m_height(0.0f) {}

    /**
    * @brief constructor that accept 4 integer
    * also create anchor on top left. Point(0,0)
    * 
    * @param x the x position of this rectangle
    * @param y the y position of this rectangle
    * @param width the width this rectangle
    * @param height the height this rectangle
    */
    Rect::Rect(float x, float y, float width, float height)
        : m_position(x, y), m_anchor(0.0f, 0.0f), m_width(width), m_height(height) {}


    /**
    * @brief constructor with the position of this rectangle
    * also create anchor on top left. Point(0,0)
    * 
    * @param position the position float point format
    * @param width the width this rectangle
    * @param height the height this rectangle
    */
    Rect::Rect(const Point& position, float width, float height)
        : m_position(position), m_anchor(0.0f, 0.0f), m_width(width), m_height(height) {}


    /**
    * @brief constructor with the position of this rectangle
    * also create anchor on top left. Point(0,0)
    * 
    * @param position the position float Point format
    * @param anchor the anchor position of this rectangle
    * @param width the width this rectangle
    * @param height the height this rectangle
    */
    Rect::Rect(const Point& position, const Point& anchor, float width, float height)
        : m_position(position), m_anchor(anchor), m_width(width), m_height(height) {}


    /***************************** Destructor *****************************/

    // Rect:~Rect() = default; //put it here in case needed

}