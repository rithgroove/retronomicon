#pragma once
#include <vector>

#include "retronomicon/lib/core/system.h"
#include "retronomicon/lib/core/entity.h"
#include "game_engine.h"
/**
 * @brief The namespace for animation utilities
 */
namespace retronomicon::lib::engine{
    /**
     * @brief The Animation System which loops all animation component and update it
     */
    using retronomicon::lib::engine::GameEngine;
    class ExitGameSystem : public retronomicon::lib::core::System {
        public:
            /***************************** Constructor *****************************/

            /**
             * @brief default constructor
             */
            ExitGameSystem(GameEngine* game_engine);

            /***************************** Destructor *****************************/

            // ~AnimationSystem(); //default destructor

            /***************************** Operator Overload *****************************/

            /**
             * @brief overloading operator << to call to_string()
             */
            friend std::ostream& operator<<(std::ostream& os, const ExitGameSystem& obj) {
                return os << obj.to_string();
            }

            /***************************** To String *****************************/

            /**
             * @brief a method to help people debug this object
             * 
             * @return Brief summary of this object in string
             */
            [[nodiscard]] virtual std::string to_string() const;
            
            /***************************** Override Method *****************************/

            /**
             * @brief method to update all component
             * 
             * @param dt time interval since last update
             * @param objects the game objects (might change to Entity Later)
             */
            void update(float dt, retronomicon::lib::core::Entity* entities)  override;

        private:
            
            /***************************** Attribute *****************************/

            GameEngine* m_gameEngine = nullptr;
    };
}