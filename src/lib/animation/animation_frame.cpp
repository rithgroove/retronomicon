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
    : m_rect((float)x, (float)y, (float)width, (float)height), // fill up m_rect
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
    : m_rect(point, (float)width, (float)height), // fill up m_rect
      m_duration(duration), //fill_up m_duration
      m_elapsedTime(0.0f) {} //set m_elapsedtime to 0

    /*
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