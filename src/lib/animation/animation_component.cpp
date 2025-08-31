#include "retronomicon/lib/animation/animation_component.h"
#include "retronomicon/lib/core/entity.h"
#include <iostream>
#include <sstream>
/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::animation {
    
    /***************************** Constructor *****************************/

    /**
     * @brief the constructor
     * 
     * @param frames the std::vector respresentation of the frames
     * @param frameCount the number of frame in this sequcne
     * @param name the name of of this animation
     * @param repeat set true if this animation is repeated
     */
    AnimationComponent::AnimationComponent(std::shared_ptr<AnimationClip> defaultClip) noexcept {
        m_defaultClip = defaultClip;
        addClip(defaultClip);
        changeClip(defaultClip->getName());
    }

    /***************************** Destructor *****************************/

    /**
     * @brief default destructor
     */
    AnimationComponent::~AnimationComponent() = default;  


    /***************************** To String *****************************/
    
    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string AnimationComponent::to_string() const{
        std::ostringstream oss;
        oss << "[AnimationComponent]\n";
        oss << "values:\n";
        oss << "- default_clip = " << m_defaultClip->getName() <<"\n";
        oss << "- current_clip = " << m_currentClip->getName() <<"\n";
        oss << "- is_paused = " << m_paused <<"\n";
        oss << "- clip list:\n";
        for (const auto& pair : m_animationClips) {
            // Access the key using pair.first and the value using pair.second
            oss << "  - "<< pair.first << "\n";
        }
        return oss.str();
    }

    /***************************** Main Methods *****************************/

    /**
     *  @brief add an animation clip to this component.
     * 
     * @param animationClip the animation clip that we'll be adding to the manager
     */
    bool AnimationComponent::addClip(std::shared_ptr<AnimationClip> clip) noexcept{
        const std::string& name = clip->getName();
        if (m_animationClips.count(name)) return false;
        m_animationClips[name] = std::move(clip);
        return true;
    }
    
    /**
     * @brief remove clip from the dictionary
     * 
     * @param name the clip name
     */
    bool AnimationComponent::removeClip(const std::string& name) {
        return m_animationClips.erase(name) > 0;
    }

    /**
     * @brief change the current animation clip.
     * 
     * @param name the name of the animation clip
     */
    void AnimationComponent::changeClip(const std::string& name){
        auto it = m_animationClips.find(name);
        if (it != m_animationClips.end()) {
            m_currentClip = it->second;
        }
    }

    /**
     * @brief insert animation clip to the Queue
     */
    void AnimationComponent::queueAnimationClip(std::shared_ptr<AnimationClip> clip) {
        if (!clip) return;
        m_animationClipsQueue.push(std::move(clip));
    }

    /**
     * @brief a method to clear the animation queue
     */
    void AnimationComponent::clearQueuedClips() {
        while (!m_animationClipsQueue.empty()) {
            m_animationClipsQueue.pop();
        }
    }

    /***************************** Override Methods *****************************/

    /**
     * @brief update function (might change in the future).
     * Potential update is to use time interval so we could do frame skipping
     * 
     * @return true if successfull, false if failed
     */
    void AnimationComponent::update(float dt){        
        if (m_paused || !m_currentClip) return;
        float leftover = dt;

        // if current clip is not the default and is finished, change it
        // this will not change if the animation is manually controlled (move,run etc, because those are repeated)
        while (leftover > 0.0f){
            leftover = m_currentClip->update(leftover);

            if (m_currentClip->isFinished()){
                if (!m_animationClipsQueue.empty()) {
                    m_currentClip = m_animationClipsQueue.front();
                    m_animationClipsQueue.pop();
                } else {
                    if (m_listener) {
                        m_listener->onAnimationFinished(this);
                    } else {
                        reset();
                    }
                    break; // Prevent another loop with a now-reset clip
                }
            }
        }
    }


}