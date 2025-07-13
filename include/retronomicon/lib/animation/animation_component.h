#pragma once

#include <unordered_map>
#include <queue>
#include <memory>
#include <string>

#include "animation_clip.h"
#include "animation_listener.h"
#include "retronomicon/lib/core/component.h"

/**
 * @brief The namespace for animation utilities
 */
namespace retronomicon::lib::animation{
    /**
     * @brief Component responsible for managing animation clip states and playback.
     */
    class AnimationComponent : public retronomicon::lib::core::Component {
        public:
            /***************************** Constructor *****************************/

            /**
             * @brief Constructor. initiate with default animation clip
             * 
             * @param defaultClip the default animation clip in shared pointer
             */
            explicit AnimationComponent(std::shared_ptr<AnimationClip> defaultClip);

            /***************************** Destructor *****************************/

            /**
             * @brief default destructor
             */
            virtual ~AnimationComponent(); 

            /***************************** Setter *****************************/

            /**
             * @brief a method to set listener when this component finished it's animation queue
             * 
             * @param listener the animation listeneer class
             */
            inline void setListener(AnimationListener* listener) { m_listener = listener; }

            /***************************** Getter *****************************/

            /**
             * @brief method to get current clip
             * 
             * @return current animation clip
             */
            inline std::shared_ptr<AnimationClip> getCurrentClip() const { return m_currentClip; }

            /**
             * @brief method to get current animation frame
             * 
             * @return current animation frame
             */
            inline const AnimationFrame& getCurrentFrame() const { return m_currentClip->getCurrentFrame(); }

            /**
             * @brief method to get current animation state name
             * 
             * @return current animation state name
             */
            inline const std::string& getCurrentStateName() const { return m_currentClip->getName(); }

            /**
             * @brief method to get current animation listener
             * 
             * @return current animation listener
             */
            inline AnimationListener* getListener() const { return m_listener; }

            /***************************** Utility *****************************/

            /**
             * @brief check is current animation is animating
             */
            bool isPlaying() const{ return !m_paused;}

            /**
             * @brief a method to check if this component have a specific animation clip
             * 
             * @param name of the clip
             */
            bool hasClip(const std::string& name) const  {return m_animationClips.count(name) > 0;}

            /***************************** Main Methods *****************************/

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
             * @brief reset animation to default animation
             */
            void reset(){ m_currentClip = m_defaultClip;}

            // --- Playback Control ---
            /**
             * @brief pause animation
             */
            void pause(){ m_paused = true; }

            /**
             * @brief resume pause animation
             */
            void resume() { m_paused = false; }         


            /***************************** Override Methods *****************************/

            /**
             * @brief update function (might change in the future).
             * Potential update is to use time interval so we could do frame skipping
             * 
             * @return true if successfull, false if failed
             */
            void update(float dt) override;

        private:
            /***************************** Attribute *****************************/
            std::unordered_map<std::string, std::shared_ptr<AnimationClip>> m_animationClips;
            std::queue<std::shared_ptr<AnimationClip>> m_animationClipsQueue;
            std::shared_ptr<AnimationClip> m_currentClip;
            std::shared_ptr<AnimationClip> m_defaultClip;
            AnimationListener* m_listener = nullptr; //not owning
            bool m_paused = false;
    };
}