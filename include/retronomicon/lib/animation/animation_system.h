#pragma once
#include <vector>

#include "retronomicon/lib/core/system.h"
#include "retronomicon/lib/core/entity.h"
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

            /***************************** Operator Overload *****************************/

            /**
             * @brief overloading operator << to call to_string()
             */
            friend std::ostream& operator<<(std::ostream& os, const AnimationSystem& obj) {
                return os << obj.to_string();
            }

            /***************************** To String *****************************/

            /**
             * @brief a method to help people debug this object
             * 
             * @return Brief summary of this object in string
             */
            virtual std::string to_string() const;
            
            /***************************** Override Method *****************************/

            /**
             * @brief method to update all component
             * 
             * @param dt time interval since last update
             * @param objects the game objects (might change to Entity Later)
             */
            void update(float dt, retronomicon::lib::core::Entity* entities)  override;
    };
}