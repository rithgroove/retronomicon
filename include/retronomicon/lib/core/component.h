#pragma once
// #include <SDL.h>
/**
 * @brief The namespace for core components
 */
namespace retronomicon::lib::core{
    // Forward declaration
    class Entity;
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
            void setOwner(Entity* owner) { this->owner = owner; }

            /**
             * @brief a method to get the owner of this component
             * 
             * @return the game object that owns this component.
             */
            Entity* getOwner() const { return owner; }

        protected:
            Entity* owner = nullptr;
    };
}