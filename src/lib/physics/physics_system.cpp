#include "retronomicon/lib/animation/physics_system.h"
#include "retronomicon/lib/animation/physics_component.h"
namespace retronomicon::lib::physics{
    AnimationSystem::PhysicsSystem() {}

    void AnimationSystem::update(float dt, vector<retronomicon::lib::core::GameObject*>& objects) {
        for (GameObject* obj : objects) {
            // render logic
            auto physicsComponent = obj->getComponent<PhysicsComponent>();
            if (!physicsComponent) continue;
            physicsComponent->update(dt);
        }
    }
}