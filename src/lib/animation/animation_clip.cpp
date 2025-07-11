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
                                 std::string name,
                                 bool repeat)
        : m_frames(frames),
          m_name(std::move(name)),
          m_repeat(repeat),
          m_currentFrame(0)
    {}

    /**
     * @brief get the current frame index
     * 
     * @return the current frame number
     */
    size_t AnimationClip::getCurrentFrameIndex() const {
        return m_currentFrame;
    }

    /**
     * @brief get the current frame
     * 
     * @return the current frame
     */
    const AnimationFrame& AnimationClip::getCurrentFrame() const {
        return m_frames.at(m_currentFrame);
    }

    /**
     * @brief update the frame to the next one
     * 
     * @return true if successful, false if failed.
     */
    float AnimationClip::update(float dt) {
        float leftover = dt;
        const size_t frameCount = m_frames.size();

        while (leftover > 0.0f) {
            auto& curFrame = m_frames[m_currentFrame];
            leftover = curFrame.update(leftover);

            if (leftover > 0.0f) {
                m_currentFrame++;
                if (m_currentFrame >= frameCount) {
                    if (m_repeat) {
                        m_currentFrame = 0;
                    } else {
                        m_currentFrame = frameCount - 1;
                        break;
                    }
                }
            }
        }

        return std::max(0.0f, leftover);
    }

    /**
     * @brief a method to check if the animation is finished?
     * 
     * @return true if m_repeat is false, and is currently on the last frame
     */
    bool AnimationClip::isFinished() const {
        // Finished if not looping and on (or past) the last frame
        return !m_repeat && (m_currentFrame + 1 >= m_frames.size());
    }


}
