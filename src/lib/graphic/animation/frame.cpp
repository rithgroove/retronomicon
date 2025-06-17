#include "retronomicon/lib/graphic/animation/frame.h"

/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::graphic::animation{

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
    Frame::Frame(int x, int y,int width, int height,RawImage* rawImage,int sequence_order, const string &name){
        m_rect = new Rect(x,y,width,height);
        m_image = rawImage;
        m_sequence_order= sequence_order;
        m_name = name;
    }

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
    Frame::Frame(Point* point ,int width, int height,RawImage* rawImage,int sequence_order,const string &name){
        m_rect = new Rect(point,width,height);
        m_image = rawImage;
        m_sequence_order= sequence_order;
        m_name = name;
    }

    /**
     * @brief basic constructor
     * 
     * @param rect the source rectangle of this frame
     * @param rawImage the raw image (might remove it later, not used)
     * @param sequence_order (a number to indicate which frame number this is)
     * @param name the name of this frame
     */
    Frame::Frame(Rect* rect,RawImage* rawImage,int sequence_order,const string &name){
        m_rect = rect;
        m_image = rawImage;
        m_sequence_order= sequence_order;
        m_name = name;
    }
    
    /**
     * @brief get the x position of this frame
     * 
     * @return x position
     */
    int Frame::getX() const {
        return m_rect->getX();
    }

    /**
     * @brief get the y position of this frame
     * 
     * @return y position
     */
    int Frame::getY() const {
        return m_rect->getY();
    }

    /**
     * the rectangle representing the source rectangle of the sprite
     * 
     * @return the source rectangle
     */
    Rect* Frame::getRect() const{
        return m_rect;
    }
}