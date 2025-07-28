#include "retronomicon/lib/physics/physics_system.h"
#include "retronomicon/lib/physics/physics_component.h"
namespace retronomicon::lib::physics{
    PhysicsSystem::PhysicsSystem() {}

    void PhysicsSystem::update(float dt, retronomicon::lib::core::Entity* entity) {
        auto physicsComponent = entity->getComponent<PhysicsComponent>();
        if (physicsComponent){
            physicsComponent->update(dt);
        }

        for (Entity* obj : entity->m_childEntities) {
            // render logic
             this->update(dt,obj);
        }
    }
}