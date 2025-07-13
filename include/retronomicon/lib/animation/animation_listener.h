#pragma once
/**
 * @brief The namespace for animation utilities
 */
namespace retronomicon::lib::animation {
    // Forward Declaration
    class AnimationComponent;

    /**
     * @brief The abstract class for animation listener
     */
    class AnimationListener {
        public:
            /***************************** Destructor *****************************/

            /**
             * @brief default destructor
             */
            virtual ~AnimationListener() = default;

            /***************************** Virtual Methods *****************************/

            /**
             * @brief Called when an animation clip finishes playing.
             * 
             * @param sender Pointer to the animation component that finished
             * might change later
             */
            virtual void onAnimationFinished(AnimationComponent* sender) = 0;
    };

}