#include "retronomicon/lib/core/rect.h"

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::core{

    /**
    * @brief constructor that accept 4 integer
    * also create anchor on top left. Point(0,0)
    * 
    * @param x the x position of this rectangle
    * @param y the y position of this rectangle
    * @param width the width this rectangle
    * @param height the height this rectangle
    */
    Rect::Rect(int x, int y, int width, int height){
        m_position = new Point(x,y);
        m_anchor = new Point(0,0);
        setSize(width,height);
    }

    /**
    * @brief constructor with the position of this rectangle
    * also create anchor on top left. Point(0,0)
    * 
    * @param position the position int Point format
    * @param width the width this rectangle
    * @param height the height this rectangle
    */
    Rect::Rect(Point* position, int width, int height){
        m_position = position;
        m_anchor = new Point(0,0);
        setSize(width,height);
    }

    /**
    * @brief constructor with the position of this rectangle
    * also create anchor on top left. Point(0,0)
    * 
    * @param position the position int Point format
    * @param anchor the anchor position of this rectangle
    * @param width the width this rectangle
    * @param height the height this rectangle
    */
    Rect::Rect(Point* position,Point* anchor, int width, int height){
        m_position = position;
        m_anchor = anchor;
        m_anchor = new Point(0,0);
        setSize(width,height);
    }

    /**
     * @brief a method to change the size of the rectangle
     * 
     * @param width the new width for this rectangle
     * @param height the new height for this rectangle
     */
    void Rect::setSize(int width,int height){
        m_width = width;
        m_height = height;
    }

   /**
    * @brief a method to change the position of the rectangle
    * 
    * @param x the new x position for this rectangle
    * @param y the new y position for this rectangle
    */
    void Rect::setPosition(int x,int y){
        m_position->set(x,y);
    }

    /**
     * @brief a method to change the position of the rectangle
     * 
     * @param position the new position in Point class
     */
    void Rect::setPosition(Point* position){
        delete m_position;
        m_position = position;
    }

    /**
     * @brief a method to get the position of the rectangle
     * 
     * @return the position in point format
     */
    Point* Rect::getPosition() const {
        return m_position;
    }

    /**
     * @brief a method to get the anchor position of the rectangle
     * 
     * @return the anchor position in point format
     */
    Point* Rect::getAnchor() const {
        return m_anchor;
    }

    /**
     * @brief a method to get the width of rectangle
     * 
     * @return the width of the rectangle
     */
    int Rect::getX() const {
        return m_position->getX();
    }

    /**
     * @brief a method to get the height of rectangle
     * 
     * @return the height of the rectangle
     */
    int Rect::getY() const {
        return m_position->getY();
    }

    /**
     * @brief a method to get the x position of this rectangle
     * 
     * @return the x position of the rectangle
     */
    int Rect::getWidth() const {
        return m_width;
    }

    /**
     * @brief a method to get the y position of this rectangle
     * 
     * @return the y position of the rectangle
     */
    int Rect::getHeight() const {
        return m_height;
    }

    /**
     * @brief a method to get SDL_Rect representation of this rectangle.
     * Useful for rendering textures.
     * 
     * @return the SDL_Rect
     */
    SDL_Rect Rect::generateSDLRect(){
        return { this->getX(), this->getY(), this->getWidth(), this->getHeight() };
    }

}