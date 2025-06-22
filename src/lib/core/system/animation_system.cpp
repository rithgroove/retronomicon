#include "retronomicon/lib/core/system/animation_system.h"

namespace retronomicon::lib::core::system{
    AnimationSystem::AnimationSystem() {}

    void AnimationSystem::update(float dt, vector<GameObject*>& objects) {
        for (GameObject* obj : objects) {
            // render logic
            obj->update(dt);
        }
    }
}