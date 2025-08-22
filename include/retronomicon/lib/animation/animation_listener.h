#pragma once

#include <string>

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
            virtual ~AnimationListener() = 0; // pure virtual destructor

            /***************************** Virtual Methods *****************************/

            /**
             * @brief Called when an animation clip finishes playing.
             * 
             * @param sender Pointer to the animation component that finished
             * might change later
             */
            virtual void onAnimationFinished(AnimationComponent* sender) = 0;

            /***************************** Operator Overload *****************************/

            /**
             * @brief overloading operator << to call to_string()
             */
            friend std::ostream& operator<<(std::ostream& os, const AnimationListener& obj) {
                return os << obj.to_string();
            }

            /***************************** To String *****************************/

            /**
             * @brief a method to help people debug this object
             * 
             * @return Brief summary of this object in string
             */
            virtual std::string to_string() const = 0;
    };

}