#include "retronomicon/system/animation_system.h"
#include "retronomicon/component/animation_component.h"

#include <sstream>

/**
 * @brief The namespace for animation utilities
 */
namespace retronomicon::syatem{
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
    void AnimationSystem::update(float dt, std::weak_ptr<Entity> weakEntity){
        if (auto entity = weakEntity.lock()) { // only proceed if entity is alive
            auto animation = entity->getComponent<AnimationComponent>();
            if (animation) {
                animation->update(dt);
            }

            // Recurse into children
            for (auto& child : entity->getChildren()) {
                this->update(dt, child);
            }
        }
    }
}