#pragma once

namespace retronomicon::lib::animation {

    class AnimationComponent;

    class AnimationListener {
    public:
        virtual ~AnimationListener() = default;

        /**
         * @brief Called when an animation clip finishes playing.
         * 
         * @param sender Pointer to the animation component that finished
         */
        virtual void onAnimationFinished(AnimationComponent* sender) = 0;
    };

}