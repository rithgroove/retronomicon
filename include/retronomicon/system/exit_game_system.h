#pragma once
#include <vector>
#include <memory>

#include "retronomicon/system/system.h"
#include "retronomicon/entity/entity.h"
#include "retronomicon/engine/game_engine.h"
/**
 * @brief The namespace for animation utilities
 */
namespace retronomicon::system{
    using retronomicon::entity::Entity;
    using retronomicon::engine::GameEngine;

    /**
     * @brief The Animation System which loops all animation component and update it
     */
    using retronomicon::engine::GameEngine;
    class ExitGameSystem : public System {
        public:
            /***************************** Constructor *****************************/

            /**
             * @brief default constructor
             */
            ExitGameSystem(std::shared_ptr<GameEngine> game_engine);

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
            void update(float dt, std::weak_ptr<Entity>  entities)  override;

        private:
            
            /***************************** Attribute *****************************/

            std::shared_ptr<GameEngine> m_gameEngine = nullptr;
    };
}