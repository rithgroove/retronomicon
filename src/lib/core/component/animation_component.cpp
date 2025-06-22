#include "retronomicon/lib/core/component/animation_component.h"

/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::core::component{

    /**
     * @brief the constructor
     * 
     * @param frames the std::vector respresentation of the frames
     * @param frameCount the number of frame in this sequcne
     * @param name the name of of this animation
     * @param repeat set true if this animation is repeated
     */
    AnimationComponent::AnimationComponent(AnimationClip* defaultClip){
        m_defaultClip = defaultClip;
        this->addClip(defaultClip);
        this->changeClip(defaultClip->getName());
    }

    /**
     *  @brief add an animation clip to this component.
     * 
     * @param animationClip the animation clip that we'll be adding to the manager
     */
    bool AnimationComponent::addClip(AnimationClip* animationClip){
        m_animationClips[animationClip->getName()] = animationClip;
    }

    /**
     * @brief change the current animation clip.
     * 
     * @param name the name of the animation clip
     */
    void AnimationComponent::changeClip(const string& name){
        m_currentClip = m_animationClips[name];
    }
    
    /**
     * @brief get the current active clip
     * 
     * @return the current clip
     */
    AnimationClip* AnimationComponent::getCurrentClip() const{
        return m_currentClip;
    }

    
    /**
     * @brief get the current active clip name
     * 
     * @return the current clip name
     */
    string AnimationComponent::getCurrentStateName() const{
        return m_currentClip->getName();
    }
   
    /**
     * @brief get the current frome of the current active clip
     * 
     * @return the current frame
     */
    Frame& AnimationComponent::getCurrentFrame() const{
        return m_currentClip->getCurrentFrame();
    }

    /**
     * @brief update function (might change in the future).
     * Potential update is to use time interval so we could do frame skipping
     * 
     * @return true if successfull, false if failed
     */
    void AnimationComponent::update(float dt){        
        float leftover = dt;
        // if current clip is not the default and is finished, change it
        // this will not change if the animation is manually controlled (move,run etc, because those are repeated)
        while (leftover > 0.0f){
            leftover = m_currentClip->update(dt);
            if (m_currentClip != m_defaultClip && m_currentClip->isFinished()){
                if (m_animationClipsQueue.empty()){
                    m_currentClip = m_defaultClip;
                }else{
                    m_animationClipsQueue.pop();
                    m_currentClip = m_animationClipsQueue.front();
                }
            }            
        }
    }


    /**
     * @brief insert animation clip to the Queue
     */
    void AnimationComponent::queueAnimationClip(AnimationClip* clip){
        m_animationClipsQueue.push(clip);
    }
}
