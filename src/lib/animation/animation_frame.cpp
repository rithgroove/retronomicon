#include "retronomicon/lib/animation/animation_frame.h"
#include <sstream>

/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::animation{
    /***************************** Using *****************************/

    using retronomicon::lib::math::Point;
    using retronomicon::lib::math::Rect;

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
     * @param duration in milisecond
     */
    AnimationFrame::AnimationFrame(const Point& point, int width, int height, float duration)
    : m_rect(point, (float)width, (float)height), // fill up m_rect
      m_duration(duration), //fill_up m_duration
      m_elapsedTime(0.0f) {} //set m_elapsedtime to 0

    /*
     * @brief basic constructor
     * 
     * @param rect the source rectangle of this frame
     * @param duration in milisecond
     */
    AnimationFrame::AnimationFrame(const Rect& rect, float duration)
    : m_rect(rect), // fill_up m_rect
      m_duration(duration), // fill_up m_duration
      m_elapsedTime(0.0f) {} //set m_elapstedtime to 0


    /***************************** Destructor *****************************/

      // AnimationFrame::~AnimationFrame() = default;

    /***************************** To String *****************************/
    
    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string AnimationFrame::to_string() const{
        std::ostringstream oss;
        oss << "[AnimationFrame]\n";
        oss << "values:\n";
        oss << "- position = ("<< m_rect.getX() << "," << m_rect.getY() << ")\n";
        oss << "- anchor   = ("<< m_rect.getAnchor().getX() << "," << m_rect.getAnchor().getY() << ")\n";
        oss << "- width    = " << m_rect.getWidth() << "\n";
        oss << "- height   = " << m_rect.getHeight() << "\n";
        oss << "- progress = " << m_elapsedTime << "/" << m_duration << "\n";
        return oss.str();
    }

    /***************************** Main Method *****************************/

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