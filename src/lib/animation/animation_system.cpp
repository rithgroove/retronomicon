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
        oss << "[AnimationSystem]\n";
        return oss.str();
    }
    /***************************** Override Method *****************************/
    
    /**
     * @brief method to update all component
     * 
     * @param dt time interval since last update
     * @param objects the game objects (might change to Entity Later)
     */
    void AnimationSystem::update(float dt, vector<retronomicon::lib::core::GameObject*>& objects) {
        for (GameObject* obj : objects) {
            // render logic
            auto animation = obj->getComponent<AnimationComponent>();
            if (!animation) continue;
            animation->update(dt);
        }
    }
}