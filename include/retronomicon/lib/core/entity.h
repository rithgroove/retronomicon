#pragma once

#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include <memory>
#include <vector>
#include <string>
#include "component.h"

using namespace std;
/**
 * @brief The namespace for core libraries such as game object and components
 */
namespace retronomicon::lib::core{
    class Entity {
        public:
            /**
             * @brief empty constructor 
             */
            Entity() = default;

            /**
             * @brief empty constructor 
             */
            Entity(const std::string &name);
            /**
             * @brief default destructor 
             */
            // ~Entity();

            /**
             * @brief start function (used to initialize stuff)
             */
            void start();

            /**
             * @brief a method to add components. this will use templates
             * 
             * @param args the component 
             */
            template <typename T, typename... Args>
            T* addComponent(Args&&... args);

            /**
             * @brief a method 
             * 
             * @param args the component 
             */
            void addEntities(unique_ptr<Entity> entity);

            /**
             * @brief a method to return a components with a specific types
             * 
             * @return the component 
             */
            template <typename T>
            T* getComponent();

            /**
             * @brief Check if the entity has a component of type T
             * 
             * @return true if the component exists
             */
            template <typename T>
            bool hasComponent() const;

            void update(float dt);
            void setName(const string& name){m_name = name;}
            std::vector<Component*> getComponents();

            const string& getName() const{return m_name;}

            Entity* createGameObject(const std::string& name);
            void removeGameObject(Entity* object);
            
            void addChildEntity(Entity* entity);
            std::vector<Entity*> getChilds(){return m_childEntities;}
            void setParent(Entity* entity){this->m_parentEntity = entity;}
            bool hasParent() const {return m_parentEntity!=nullptr;}

            Entity* getParent() const {return m_parentEntity;}
        protected:
            std::vector<Entity*> m_childEntities;
            Entity* m_parentEntity = nullptr;
            unordered_map<type_index, unique_ptr<Component>> m_components;
            string m_name;
    };

    // ---------- Template definitions ----------
     /**
     * @brief The template for add component method
     */
    template <typename T, typename... Args>
    T* Entity::addComponent(Args&&... args) {
        // generate index based on class type
        type_index typeId = type_index(typeid(T));

        // check if exist or not (count is a method that used by unordered_map and order)
        if (m_components.count(typeId) == 0) {

            // create new instance of said component (forwarding the arguments)
            T* rawPtr = new T(forward<Args>(args)...);

            // set the owner of the components to this entity
            rawPtr->setOwner(this);

            // save to our map (use unique_ptr so it automatically cleaned if it removed from the map)
            m_components[typeId] = unique_ptr<Component>(rawPtr);

            //return the component
            return rawPtr;
        }

        //return null if exists
        return nullptr;
    }

     /**
     * @brief The template for get component method
     */
    template <typename T>
    T* Entity::getComponent() {
        // generate index based on class type
        type_index typeId = type_index(typeid(T));

        // find the unique_ptr containing the component
        auto it = m_components.find(typeId);

        // check if we found the component
        if (it != m_components.end()) {
            // return the down casted components (because we use unique_ptr)
            return dynamic_cast<T*>(it->second.get());
        }

        //return null if not exist
        return nullptr;
    }

    template <typename T>
    bool Entity::hasComponent() const {
        type_index typeId = type_index(typeid(T));
        return m_components.count(typeId) > 0;
    }

}
