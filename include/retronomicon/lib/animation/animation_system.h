#pragma once
#include <vector>

#include "retronomicon/lib/core/system.h"
#include "retronomicon/lib/core/game_object.h"
/**
 * @brief The namespace for animation utilities
 */
namespace retronomicon::lib::animation{
    /**
     * @brief The Animation System which loops all animation component and update it
     */
    class AnimationSystem : public retronomicon::lib::core::System {
        public:
            /***************************** Constructor *****************************/

            /**
             * @brief default constructor
             */
            AnimationSystem();

            /***************************** Destructor *****************************/

            // ~AnimationSystem(); //default destructor

            /***************************** Override Method *****************************/

            /**
             * @brief method to update all component
             * 
             * @param dt time interval since last update
             * @param objects the game objects (might change to Entity Later)
             */
            void update(float dt, vector<retronomicon::lib::core::GameObject*>& objects)  override;
    };
}