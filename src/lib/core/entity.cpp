#include "retronomicon/lib/core/entity.h"

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::core{

    void Entity::start() {
        //loop all components and call start
        for (auto& pair : m_components) {
            pair.second->start();
        }
    }

    void Entity::update(float dt) {
        //loop all components and call update        
        for (auto& pair : m_components) {
            pair.second->update(dt);
        }
    }

    void Entity::render(SDL_Renderer* renderer) {
        //loop all components and call render
        for (auto& pair : m_components) {
            pair.second->render(renderer);
        }
    }
}