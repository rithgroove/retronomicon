#include "retronomicon/lib/animation/animation_clip.h"
#include <algorithm>  // for std::max

/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::animation{

    /**
     * @brief the constructor
     * 
     * @param frames the std::vector respresentation of the frames
     * @param name the name of of this animation
     * @param repeat set true if this animation is repeated
     */
    AnimationClip::AnimationClip(const std::vector<AnimationFrame>& frames,
                                 std::string& name,
                                 bool repeat)
        : m_frames(frames),
          m_name(std::move(name)),
          m_repeat(repeat),
          m_currentFrame(0)
    {}

    /**
     * @brief update the frame to the next one
     * 
     * @return true if successful, false if failed.
     */
    float AnimationClip::update(float dt){
        float leftOver = dt;
        while (leftOver >0.0f){
            AnimationFrame *curFrame = &m_frames[m_currentFrame];
            leftOver = curFrame->update(leftOver);
            if (leftOver > 0.0f){
                m_currentFrame++;
                if (m_currentFrame >= getFrameCount()){
                    if (m_repeat){
                        m_currentFrame = 0;
                    }else{
                        m_currentFrame--;
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

    /**
     * @brief a method to check if the animation is finished?
     * 
     * @return true if m_repeat is false, and is currently on the last frame
     */
    bool AnimationClip::isFinished() const{
        if (m_repeat && m_currentFrame >= getFrameCount()){
            return true;
        }
        return false;
    }

}
