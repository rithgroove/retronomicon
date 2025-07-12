#pragma once

#include <unordered_map>
#include <queue>
#include <memory>
#include <string>

#include "animation_clip.h"
#include "animation_listener.h"
#include "retronomicon/lib/core/component.h"

/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::animation{
    /**
     * @brief Component responsible for managing animation clip states and playback.
     */
    class AnimationComponent : public retronomicon::lib::core::Component {
        public:
            /**
             * @brief Constructor. initiate with default animation clip
             * 
             * @param defaultClip the default animation clip in shared pointer
             */
            explicit AnimationComponent(std::shared_ptr<AnimationClip> defaultClip);
            virtual ~AnimationComponent(); 

            // --- Clip Management ---

            /**
             *  @brief add a clip to this state.
             * 
             * @param animationClip the animation clip that we'll be adding to the manager
             */
            bool addClip(std::shared_ptr<AnimationClip> clip);

            /**
             * @brief remove clip from the dictionary
             * 
             * @param the clip name
             */
            bool removeClip(const std::string& name);
            
            /**
             * @brief change the current clip.
             * 
             * @param name the name of the animation clip
             */
            void changeClip(const std::string& name);

            /**
             * @brief insert clip to clip Queue
             */
            void queueAnimationClip(std::shared_ptr<AnimationClip> clip);

            /**
             * @brief a method to clear the animation queue
             */
            void clearQueuedClips();

            /**
             * @brief a method to check if this component have a specific animation clip
             * 
             * @param name of the clip
             */
            bool hasClip(const std::string& name) const ;
            
            /**
             * @brief reset animation to default animation
             */
            void reset();


            // --- Playback Control ---
            /**
             * @brief pause animation
             */
            void pause();

            /**
             * @brief resume pause animation
             */
            void resume();

            /**
             * @brief check is current animation is animating
             */
            bool isPlaying() const;


            // --- Core Update ---
            /**
             * @brief update function (might change in the future).
             * Potential update is to use time interval so we could do frame skipping
             * 
             * @return true if successfull, false if failed
             */
            void update(float dt) override;


            // Inline Getters and Setter
            inline std::shared_ptr<AnimationClip> getCurrentClip() const { return m_currentClip; }
            inline const AnimationFrame& getCurrentFrame() const { return m_currentClip->getCurrentFrame(); }
            inline const std::string& getCurrentStateName() const { return m_currentClip->getName(); }
            inline void setListener(AnimationListener* listener) { m_listener = listener; }
            inline AnimationListener* getListener() const { return m_listener; }
        private:
            std::unordered_map<std::string, std::shared_ptr<AnimationClip>> m_animationClips;
            std::queue<std::shared_ptr<AnimationClip>> m_animationClipsQueue;
            std::shared_ptr<AnimationClip> m_currentClip;
            std::shared_ptr<AnimationClip> m_defaultClip;
            AnimationListener* m_listener = nullptr; //not owning
            bool m_paused = false;
    };
}