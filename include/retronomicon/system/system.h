#pragma once
#include <memory>
#include "retronomicon/entity/entity.h"


namespace retronomicon::system {
    using retronomicon::entity::Entity;
    /**
     * @brief Base class for all systems.
     * Every system must at least implement update().
     */
    class System {
        public:
            virtual ~System() = default;

            /**
             * @brief Update logic for this system.
             * @param dt Delta time since last frame.
             * @param entity Root entity of the scene/subtree to process.
             */
            virtual void update(float dt, std::weak_ptr<Entity> entity) = 0;
    };
}
