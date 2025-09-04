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
    class Renderable;
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
            std::shared_ptr<Renderable> getMainRenderableComponent(){return m_mainRenderableComponent;}
            void setMainRenderableComponent(std::shared_ptr<Renderable> renderable){m_mainRenderableComponent = renderable;}

            bool isVisible() {return visible;}
            void setVisible() {visible = true;}
            void setInvisible() {visible = false;}
        protected:
            bool visible = true;
            std::vector<Entity*> m_childEntities;
            std::shared_ptr<Renderable> m_mainRenderableComponent = nullptr;
            Entity* m_parentEntity = nullptr;
            unordered_map<type_index, shared_ptr<Component>> m_components;
            string m_name;
    };

    // ---------- Template definitions ----------
     /**
     * @brief The template for add component method
     */
    template <typename T, typename... Args>
    T* Entity::addComponent(Args&&... args) {
        type_index typeId = type_index(typeid(T));

        if (m_components.count(typeId) == 0) {
            // create the component
            T* rawPtr = new T(std::forward<Args>(args)...);
            rawPtr->setOwner(this);

            std::shared_ptr<Component> compPtr(rawPtr);
            m_components[typeId] = compPtr;

            // If T is also a Renderable, and we don't yet have a main one
            if (!m_mainRenderableComponent) {
                if constexpr (std::is_base_of<Renderable, T>::value) {
                    m_mainRenderableComponent = std::shared_ptr<Renderable>(compPtr, rawPtr);
                }
            }

            return rawPtr;
        }

        return nullptr;
    }

     /**
     * @brief The template for get component method
     */
    // template <typename T>
    // T* Entity::getComponent() {
    //     // generate index based on class type
    //     type_index typeId = type_index(typeid(T));

    //     // find the unique_ptr containing the component
    //     auto it = m_components.find(typeId);

    //     // check if we found the component
    //     if (it != m_components.end()) {
    //         // return the down casted components (because we use unique_ptr)
    //         return dynamic_cast<T*>(it->second.get());
    //     }

    //     //return null if not exist
    //     return nullptr;
    // }

    template <typename T>
    T* Entity::getComponent() {
        for (auto& [typeId, comp] : m_components) {
            if (auto casted = dynamic_cast<T*>(comp.get())) {
                return casted;
            }
        }
        return nullptr;
    }

    template <typename T>
    bool Entity::hasComponent() const {
        type_index typeId = type_index(typeid(T));
        return m_components.count(typeId) > 0;
    }

}
