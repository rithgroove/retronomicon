#include "retronomicon/lib/core/entity.h"
#include <algorithm> // for std::remove
#include <vector>
/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::core{
    /***************************** Constructor *****************************/

    /**
     * @brief empty constructor 
     * 
     * @param name the name of this entity
     */
    Entity::Entity(const std::string &name):m_name(name){}
    
    /***************************** Constructor *****************************/
    
    /**
     * @brief start function (used to initialize stuff)
     */    
    void Entity::start() {
        //loop all components and call start
        for (auto& pair : m_components) {
            pair.second->start();
        }
        for (auto& child : m_childEntities) {
            child->start();
        }
    }

    /**
     * @brief a method to add child entity
     * 
     * @param args the child entity
     */
    void Entity::addChildEntity(Entity* entity){
        m_childEntities.push_back(entity);
        entity->setParent(this);
    }

    /**
     * @brief a method to remove a child entity
     * 
     * @param args the child entity
     */
    void Entity::removeChildEntity(Entity* entity) {
        auto it = std::remove(m_childEntities.begin(), m_childEntities.end(), entity);
        if (it != m_childEntities.end()) {
            m_childEntities.erase(it, m_childEntities.end());
            if (entity->getParent() == this) {
                entity->setParent(nullptr);
            }
        }
    }
    
    /**
     * @brief method to get all components
     * 
     * @return list of component in vector formats
     */
    std::vector<Component*> Entity::getComponents() {
        std::vector<Component*> components;
        for (auto& [type, ptr] : m_components) {
            components.push_back(ptr.get());
        }
        return components;
    }
}