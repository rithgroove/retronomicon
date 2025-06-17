#pragma once

class GameObject; // Forward declaration

/**
 * @brief The namespace for core libraries such as game object and components
 */
namespace retronomicon::lib::core::component{
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
         * @brief a method to render the component if any
         */
        virtual void render() {}

        /**
         * @brief a to set the owner of this component
         * 
         * @param owner the game object that owns this.
         */
        void setOwner(GameObject* owner) { this->owner = owner; }

        /**
         * @brief a method to get the owner of this component
         * 
         * @return the game object that owns this component.
         */
        GameObject* getOwner() const { return owner; }

    protected:
        GameObject* owner = nullptr;
    };
}