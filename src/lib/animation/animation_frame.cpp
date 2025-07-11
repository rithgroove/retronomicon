#include "retronomicon/lib/animation/animation_frame.h"
/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::animation{
    using retronomicon::lib::math::Point;
    using retronomicon::lib::math::Rect;
    /**
     * @brief basic constructor fill up stack directly 
     * ("new Rect" will create in heap bad bad)
     * 
     * @param x the x position of the start of the current frame from the spritesheet
     * @param y the y position of the start of the current frame from the spritesheet
     * @param width the width of the current frame from the spritesheet
     * @param height the height of the current frame from the spritesheet
     * @param sequence_order (a number to indicate which frame number this is)
     * @param name the name of this frame
     */    
    AnimationFrame::AnimationFrame(int x, int y, int width, int height, float duration)
    : m_rect(x, y, width, height), // fill up m_rect
      m_duration(duration), //fill_up m_duration
      m_elapsedTime(0.0f) {} //set m_elapsedtime to 0

    /**
     * @brief basic constructor
     * 
     * @param point the point representing the starting point of this frame
     * @param width the width of the current frame from the spritesheet
     * @param height the height of the current frame from the spritesheet
     * @param sequence_order (a number to indicate which frame number this is)
     * @param name the name of this frame
     */
    AnimationFrame::AnimationFrame(const Point& point, int width, int height, float duration)
    : m_rect(point, width, height), // fill up m_rect
      m_duration(duration), //fill_up m_duration
      m_elapsedTime(0.0f) {} //set m_elapsedtime to 0

    /**
     * @brief basic constructor
     * 
     * @param rect the source rectangle of this frame
     * @param sequence_order (a number to indicate which frame number this is)
     * @param name the name of this frame
     */
    AnimationFrame::AnimationFrame(const Rect& rect, float duration)
    : m_rect(rect), // fill_up m_rect
      m_duration(duration), // fill_up m_duration
      m_elapsedTime(0.0f) {} //set m_elapstedtime to 0
    
    /**
     * @brief get the x position of this frame
     * 
     * @return x position
     */
    int AnimationFrame::getX() const {
        return m_rect.getX();
    }

    /**
     * @brief get the y position of this frame
     * 
     * @return y position
     */
    int AnimationFrame::getY() const {
        return m_rect.getY();
    }

    /**
     * @brief get the width of this frame
     * 
     * @return width
     */
    int AnimationFrame::getWidth() const {
        return m_rect.getWidth();
    }

    /**
     * @brief get the height of this frame
     * 
     * @return height
     */
    int AnimationFrame::getHeight() const {
        return m_rect.getHeight();
    }

    /**
     * the rectangle representing the source rectangle of the sprite
     * 
     * @return the source rectangle
     */
    const Rect& AnimationFrame::getRect() const {
        return m_rect;
    }


    /**
     * @brief a method to reset spent duration (set m_elapsedTime to 0)
     */
    void AnimationFrame::reset(){
        m_elapsedTime = 0.0f;
    }

    /**
     * @brief check how many time spent on this frame
     * 
     * @return left over delta time
     */
    float AnimationFrame::update(float dt){
        m_elapsedTime += dt;
        
        if (m_elapsedTime > m_duration){
            float leftover =  m_elapsedTime - m_duration; 
            reset();
            return leftover;
        }else{
            return 0.0f;
        }
    }
}