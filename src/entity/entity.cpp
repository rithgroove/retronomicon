#include "retronomicon/entity/entity.h"
#include "retronomicon/component/component.h"
#include "retronomicon/component/renderable.h"
#include <algorithm> // for std::remove
#include <vector>
#include <iostream>
/**
 * @brief The namespace for entities, scene etc
 */
namespace retronomicon::entity{
    /***************************** Constructor *****************************/

    /**
     * @brief empty constructor 
     * 
     * @param name the name of this entity
     */
    Entity::Entity(const std::string &name):m_name(name){}
    
    /***************************** Destructore *****************************/
    
    /**
     * @brief overidable destructor. calls shutdown()
     */
    Entity::~Entity() {
        shutdown();
    }

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
        m_isInitialized = true;
    }

    /**
     * @brief a method to add child entity
     * 
     * @param args the child entity
     */
    void Entity::addChildEntity(const std::shared_ptr<Entity>& child) {
        if (!child) return;
        child->setParent(shared_from_this());
        this->m_childEntities.push_back(child);
    }

    /**
     * @brief a method to remove a child entity
     * 
     * @param args the child entity
     */
    void Entity::removeChildEntity(const std::shared_ptr<Entity>& child) {

        auto it = std::remove(m_childEntities.begin(), m_childEntities.end(), child);
        if (it != m_childEntities.end()) {
            m_childEntities.erase(it, m_childEntities.end());
            if (child->getParent() == shared_from_this()) {
                child->setParent(nullptr);
            }
        }
    }

    /**
     * @brief method to get all components
     * 
     * @return list of component in vector formats
     */
    std::vector<std::shared_ptr<Component>> Entity::getComponents() {
        std::vector<std::shared_ptr<Component>> components;
        for (auto& [type, ptr] : m_components) {
            components.push_back(ptr);
        }
        return components;
    }

    /**
     * @brief method to shutdown and delete all child entities
     */
    void Entity::shutdown() {
        // Clean up components if needed
        m_components.clear();
        
        // Shutdown children first (recursive!)
        for (auto& child : m_childEntities) {
            child->shutdown();
        }
        m_childEntities.clear();

        m_isInitialized = false;
    }
}