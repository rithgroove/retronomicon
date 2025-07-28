#include "retronomicon/lib/animation/animation_system.h"
#include "retronomicon/lib/animation/animation_component.h"

#include <sstream>

/**
 * @brief The namespace for animation utilities
 */
namespace retronomicon::lib::animation{
    /***************************** Constructor *****************************/
    
    /**
     * @brief default constructor
     */
    AnimationSystem::AnimationSystem() {}

    /***************************** Destructor *****************************/

    // AnimationSystem::~AnimationSystem() = default;

    /***************************** To String *****************************/
    
    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string AnimationSystem::to_string() const{
        std::ostringstream oss;
        oss << "[Animation System]\n";
        return oss.str();
    }
    /***************************** Override Method *****************************/
    
    /**
     * @brief method to update all component
     * 
     * @param dt time interval since last update
     * @param entity the parent entity, will call this method recursively
     */
    void AnimationSystem::update(float dt, retronomicon::lib::core::Entity* entity){
        auto animation = entity->getComponent<AnimationComponent>();
        if (animation){
            animation->update(dt);
        }

        for (Entity* obj : entity->m_childEntities) {
            // render logic
             this->update(dt,obj);
        }
    }
}