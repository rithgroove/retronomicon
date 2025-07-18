#include "retronomicon/lib/physics/physics_system.h"
#include "retronomicon/lib/physics/physics_component.h"
namespace retronomicon::lib::physics{
    PhysicsSystem::PhysicsSystem() {}

    void PhysicsSystem::update(float dt, vector<retronomicon::lib::core::GameObject*>& objects) {
        for (GameObject* obj : objects) {
            // render logic
            auto physicsComponent = obj->getComponent<PhysicsComponent>();
            if (!physicsComponent) continue;
            physicsComponent->update(dt);
        }
    }
}