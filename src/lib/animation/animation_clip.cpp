#include "retronomicon/lib/animation/animation_clip.h"
#include <algorithm>  // for std::max
#include <sstream>
#include <iostream>
/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::animation{

    /***************************** Constructor *****************************/

    /**
     * @brief the constructor
     * 
     * @param frames the std::vector respresentation of the frames
     * @param name the name of of this animation
     * @param repeat set true if this animation is repeated
     */
    AnimationClip::AnimationClip(const std::vector<AnimationFrame>& frames,
                                 const std::string& name,
                                 bool repeat)
        : m_frames(frames),
          m_name(std::move(name)),
          m_repeat(repeat),
          m_currentFrame(0)
    {
        std::cout<<"repeat : " <<repeat<<std::endl;

    }

    
    /***************************** Destructor *****************************/

      // AnimationClip::~AnimationClip() = default;


    /***************************** Utility *****************************/

    /**
     * @brief a method to check if the animation is finished?
     * 
     * @return true if m_repeat is false, and is currently on the last frame
     */
    bool AnimationClip::isFinished() const{
        if (!m_repeat && m_currentFrame >= getFrameCount()){
            return true;
        }
        return false;
    }

    /***************************** To String *****************************/
    
    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string AnimationClip::to_string() const{
        std::ostringstream oss;
        oss << "[AnimationClip]\n";
        oss << "values:\n";
        oss << "- name          = " << m_name <<"\n";
        oss << "- repeat        = " << m_repeat <<"\n";
        oss << "- current_frame = " << m_currentFrame << "/" << getFrameCount() <<"\n";
        return oss.str();
    }

    /***************************** Main Methods *****************************/

    /**
     * @brief update the frame to the next one
     * 
     * @return true if successful, false if failed.
     */
    float AnimationClip::update(float dt){
        float leftOver = dt;
        while (leftOver >0.0f){
            AnimationFrame *curFrame = &m_frames[m_currentFrame];
            // std::cout << m_frames[m_currentFrame] <<std::endl;
            leftOver = curFrame->update(leftOver);
            if (leftOver > 0.0f){
                m_currentFrame++;
                if (m_currentFrame >= getFrameCount()){
                    if (m_repeat){
                        m_currentFrame = 0;
                    }else{
                        break;
                    }
                }
            }
        }
        if (leftOver < 0.0f){
            leftOver = 0.0f;
        }
        return leftOver;
    }
}
