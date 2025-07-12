#include "retronomicon/lib/animation/animation_system.h"
#include "retronomicon/lib/animation/animation_component.h"
namespace retronomicon::lib::animation{
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