#pragma once

class GameObject; // Forward declaration

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::core{
    class Component {
    public:
        Component() = default;
        virtual ~Component() = default;

        virtual void start() {}
        virtual void update(float dt) {}
        virtual void render() {}

        void setOwner(GameObject* owner) { this->owner = owner; }
        GameObject* getOwner() const { return owner; }

    protected:
        GameObject* owner = nullptr;
    };
}