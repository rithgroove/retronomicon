#include "retronomicon/lib/core/entity.h"
#include <algorithm> // for std::remove
#include <vector>
/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::core{

    Entity::Entity(const std::string &name):m_name(name){}
    
    void Entity::start() {
        //loop all components and call start
        for (auto& pair : m_components) {
            pair.second->start();
        }
    }
    
    Entity* Entity::createGameObject(const std::string& name) {
        Entity* obj = new Entity(); // optional: set name if Entity supports it
        m_childEntities.push_back(obj);
        return obj;
    }

    void Entity::removeGameObject(Entity* object) {
        auto it = std::remove(m_childEntities.begin(), m_childEntities.end(), object);
        if (it != m_childEntities.end()) {
            delete *it;
            m_childEntities.erase(it, m_childEntities.end());
        }
    }

    std::vector<Component*> Entity::getComponents() {
        std::vector<Component*> components;
        for (auto& [type, ptr] : m_components) {
            components.push_back(ptr.get());
        }
        return components;
    }
}