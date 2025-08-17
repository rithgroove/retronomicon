#include "retronomicon/lib/engine/exit_game_system.h"
#include "retronomicon/lib/engine/exit_game_component.h"

#include <sstream>
#include <iostream>
/**
 * @brief The namespace for animation utilities
 */
namespace retronomicon::lib::engine{
    /***************************** Constructor *****************************/
    
    /**
     * @brief default constructor
     */
    ExitGameSystem::ExitGameSystem(GameEngine* gameEngine):m_gameEngine(gameEngine) {}

    /***************************** Destructor *****************************/

    // AnimationSystem::~AnimationSystem() = default;

    /***************************** To String *****************************/
    
    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string ExitGameSystem::to_string() const{
        std::ostringstream oss;
        oss << "[Exit Game System]\n";
        return oss.str();
    }
    /***************************** Override Method *****************************/
    
    /**
     * @brief method to update all component
     * 
     * @param dt time interval since last update
     * @param entity the parent entity, will call this method recursively
     */
    void ExitGameSystem::update(float dt, retronomicon::lib::core::Entity* entity){
        auto egc = entity->getComponent<ExitGameComponent>();
        if (egc->isActivated()){
            m_gameEngine->stop();
        }

        for (Entity* obj : entity->getChilds()) {
            // render logic
             this->update(dt,obj);
        }
    }
}