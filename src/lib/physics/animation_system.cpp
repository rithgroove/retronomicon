#include "retronomicon/lib/animation/physics_system.h"
#include "retronomicon/lib/animation/physics_component.h"
namespace retronomicon::lib::physics{
    AnimationSystem::AnimationSystem() {}

    void AnimationSystem::update(float dt, vector<retronomicon::lib::core::GameObject*>& objects) {
        for (GameObject* obj : objects) {
            // render logic
            auto animation = obj->getComponent<AnimationComponent>();
            if (!animation) continue;
            animation->update(dt);
        }
    }
}