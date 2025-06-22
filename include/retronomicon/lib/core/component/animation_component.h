#pragma once

#include <unordered_map>
#include <queue>
#include "retronomicon/lib/graphic/animation/animation_clip.h"
#include "component.h"

using namespace retronomicon::lib::math;
using namespace retronomicon::lib::graphic::animation;

/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::core::component{
    /**
     * @brief A class that represent a frame in the animation clip (the source image from sprite sheet)
     */
    class AnimationComponent : public Component {
        public:
            /**
             * @brief Constructor. initiate with default animation clip
             * 
             * @param defaultClip the default animation clip
             */
            AnimationComponent(AnimationClip* defaultClip);

            /**
             *  @brief add a clip to this state.
             * 
             * @param animationClip the animation clip that we'll be adding to the manager
             */
            bool addClip(AnimationClip* animationClip);

            /**
             * @brief change the current clip.
             * 
             * @param name the name of the animation clip
             */
            void changeClip(const string& name);

            /**
             * @brief get the current active clip
             * 
             * @return the current clip
             */
            AnimationClip* getCurrentClip() const;


            /**
             * @brief get the current frome of the current active clip
             * 
             * @return the current frame
             */
            Frame& getCurrentClip() const;

            /**
             * @brief get the current active clip name
             * 
             * @return the current clip name
             */
            string getCurrentStateName() const;

            /**
             * @brief update function (might change in the future).
             * Potential update is to use time interval so we could do frame skipping
             * 
             * @return true if successfull, false if failed
             */
            void update(float dt) override;

            /**
             * @brief insert clip to clip Queue
             */
            void queueAnimationClip(AnimationClip* clip);
        private:
            unordered_map<string, AnimationClip*> m_animationClips;
            queue<AnimationClip*> m_animationClipsQueue;
            AnimationClip* m_currentClip;
            AnimationClip* m_defaultClip;
    };
}