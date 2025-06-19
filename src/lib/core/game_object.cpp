#include "retronomicon/lib/core/game_object.h"

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::core{
    GameObject::GameObject(const string& name) {
        m_name = name;
    }

    GameObject::~GameObject() {}

    void GameObject::start() {
        //loop all components and call start
        for (auto& pair : components) {
            pair.second->start();
        }
    }

    void GameObject::update(float dt) {
        //loop all components and call update        
        for (auto& pair : components) {
            pair.second->update(dt);
        }
    }

    void GameObject::render() {
        //loop all components and call render
        for (auto& pair : components) {
            pair.second->render();
        }
    }
}