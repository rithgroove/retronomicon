#include "retronomicon/lib/graphic/animation/sequence.h"

/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::graphic::animation{

    /**
     * @brief the constructor
     * 
     * @param frames the std::vector respresentation of the frames
     * @param frameCount the number of frame in this sequcne
     * @param name the name of of this animation
     * @param repeat set true if this animation is repeated
     */
    Sequence::Sequence(vector<Frame> frames, int frameCount, const string &name , bool repeat){
    	m_frames = frames;
    	m_frameCount = frameCount;
        m_name = name;
        m_repeat = repeat;
        m_currentFrame = 0;
    }

    /**
     * @brief get the current frame index
     * 
     * @return the current frame number
     */
    int Sequence::getCurrentFrameIndex(){
    	return m_currentFrame;
    }

    /**
     * @brief get the current frame
     * 
     * @return the current frame
     */
    Frame& Sequence::getCurrentFrame(){
    	return m_frames.at(m_currentFrame);
    }
    
    /**
     * @brief get the name of this sequence
     * 
     * @return name of the sequence
     */
    string Sequence::getName() const{
        return m_name;
    }


    /**
     * @brief update the frame to the next one
     * 
     * @return true if successful, false if failed.
     */
    float Sequence::update(float dt){
        float leftOver = dt;
        while (leftOver >0.0f){
            Frame* curFrame = m_frames[m_currentFrame];
            leftOver = curFrame->update(leftOver);
            if (leftOver > 0.0f){
                m_currentFrame++;
                if (m_currentFrame >= m_frameCount){
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
            leftOver = 0.0f
        }
        return leftOver;
    }

    /**
     * @brief a method to check if the animation is finished?
     * 
     * @return true if m_repeat is false, and is currently on the last frame
     */
    bool Sequence::isFinished(){
        if (m_repeat && m_currentFrame >= m_frameCount){
            return true;
        }
        return false;
    }

}
