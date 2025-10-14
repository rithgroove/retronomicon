#pragma once
#include <memory>
#include "retronomicon/entity/entity.h"

/**
 * @brief The namespace for core components
 */
namespace retronomicon::component{
    using retronomicon::entity::Entity;

    /**
     * @brief The interface for components (so we could easily includes multiple tipes in game objects)
     */
    class Component {
        public:

            /**
             * @brief empty constructor 
             */
            Component() = default;

            /**
             * @brief virtual destructor, if not defined use default;
             */
            virtual ~Component() = default;

            /**
             * @brief start function (used to initialize stuff)
             */
            virtual void start() {}

            /**
             * @brief method to update the component
             * 
             * @param dt time interval since last update
             */
            virtual void update(float dt) {}

            /**
             * @brief a to set the owner of this component
             * 
             * @param owner the game object that owns this.
             */
            void setOwner(std::shared_ptr<Entity> owner) { this->owner = owner; }

            /**
             * @brief a method to get the owner of this component
             * 
             * @return the game object that owns this component.
             */
            std::shared_ptr<Entity> getOwner() const { return owner.lock(); }

        protected:
            std::weak_ptr<Entity> owner;  ///< Non-owning reference to Entity
    };
}