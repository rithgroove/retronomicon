#include "retronomicon/lib/core/game_object.h"

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::core{
    GameObject::GameObject() {}

    GameObject::~GameObject() {}

    void GameObject::start() {
        for (auto& pair : components) {
            pair.second->start();
        }
    }

    void GameObject::update(float dt) {
        for (auto& pair : components) {
            pair.second->update(dt);
        }
    }

    void GameObject::render() {
        for (auto& pair : components) {
            pair.second->render();
        }
    }
}