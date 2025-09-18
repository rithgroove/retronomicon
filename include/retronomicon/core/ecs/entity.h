#pragma once

#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include <memory>
#include <vector>
#include <string>
#include "component.h"
#include "renderable.h"

using namespace std;
/**
 * @brief The namespace for ECS libraries that will be the building blocks for the engine
 */
namespace retronomicon::core::ecs{

    /**
     * @brief forward declaration of renderable
     */ 
    class Renderable;

    /**
     * @brief Entity class that represent almost anything in the game
     */ 
    class Entity  : public std::enable_shared_from_this<Entity>{
        public:
            /***************************** Constructor *****************************/
            /**
             * @brief empty constructor 
             */
            Entity() = default;

            /**
             * @brief empty constructor 
             * 
             * @param name the name of this entity
             */
            explicit Entity(const std::string& name);

            /***************************** Destructor *****************************/

            /**
             * @brief default destructor 
             */
            // ~Entity();

            /***************************** Setter *****************************/

            /**
             * @brief method make this entity visible
             */
            void setVisible() {m_visible = true;}

            /**
             * @brief method make this entity invisible
             */
            void setInvisible() {m_visible = false;}

            /**
             * @brief method to change the name of this entity
             * 
             * @param name the name of this entity
             */
            void setName(const string& name){m_name = name;}

            /**
             * @brief method to set the parent of this entity
             * 
             * @param entity parent entity
             */
            void setParent(const std::shared_ptr<Entity>& entity) {
                m_parentEntity = entity;
            }

            /***************************** Getter *****************************/

            /**
             * @brief a method to check if this instance is initialized or not.
             * 
             * @return true if start() have been called
             */            
            bool isInitialized() const { return m_isInitialized; }
            
            /**
             * @brief method to get whether or not this entity is visible?
             * 
             * @return true if visible
             */
            bool isVisible() {return m_visible;}

            /**
             * @brief method to get this entity parents
             * 
             * @return shared ptr of parent entity
             */
            std::shared_ptr<Entity> getParent() const { return m_parentEntity.lock(); }

            /**
             * @brief get the vector of it's childrens
             * 
             * @return list (in vector class object) of this entity's childrens
             */
            std::vector<std::shared_ptr<Entity>> getChildren() const { return m_childEntities; }

            /**
             * @brief a method to check this class parents
             * 
             * @return true if it has parent
             */
            bool hasParent() const { return !m_parentEntity.expired(); }        

            /**
             * @brief a method to get entity name
             * 
             * @return the name of this entity
             */
            const string& getName() const{return m_name;}


            /**
             * @brief method to get all components
             * 
             * @return list of component in vector formats
             */
            std::vector<std::shared_ptr<Component>> getComponents();

            /***************************** Utilities *****************************/


            /***************************** Main Method *****************************/
            /**
             * @brief start function (used to initialize stuff)
             */
            virtual void start();

            /**
             * @brief a method to add child entity
             * 
             * @param args the child entity
             */
            void addChildEntity(const std::shared_ptr<Entity>& child);

            /**
             * @brief a method to remove a child entity
             * 
             * @param args the child entity
             */
            void removeChildEntity(const std::shared_ptr<Entity>& child);
        
            
            /*********** Component Related Method [using c++ template] *************/

            /**
             * @brief a method to add components. this will use templates
             * 
             * @param args the component 
             */
            template <typename T, typename... Args>
            std::shared_ptr<T> addComponent(Args&&... args);

            /**
             * @brief a method to return a components with a specific types
             * 
             * @return the component 
             */
            template <typename T>
            std::shared_ptr<T>  getComponent();

            /**
             * @brief Check if the entity has a component of type T
             * 
             * @return true if the component exists
             */
            template <typename T>
            bool hasComponent() const;


        protected:
            /***************************** Attribute *****************************/
            bool m_visible = true; // visibility flag
            bool m_isInitialized = false;
            std::string m_name; // name of this entity

            std::vector<std::shared_ptr<Entity>> m_childEntities; //child entity
            std::weak_ptr<Entity> m_parentEntity;

            std::unordered_map<std::type_index, std::shared_ptr<Component>> m_components;
    };

    // ---------- Template definitions ----------
     /**
     * @brief The template for add component method
     * 
     * @return the added component
     */
    template <typename T, typename... Args>
    std::shared_ptr<T> Entity::addComponent(Args&&... args) {
        type_index typeId = type_index(typeid(T));

        if (m_components.count(typeId) == 0) {
            auto compPtr = std::make_shared<T>(std::forward<Args>(args)...);
            compPtr->setOwner(this);
            m_components[typeId] = compPtr;

            return compPtr;
        }

        return nullptr;
    }

    /**
     * @brief The template for get component method
     * 
     * @return the component
     */
    template <typename T>
    std::shared_ptr<T> Entity::getComponent() {
        for (auto& [typeId, comp] : m_components) {
            if (auto casted = std::dynamic_pointer_cast<T>(comp)) {
                return casted;
            }
        }
        return nullptr;
    }

    /**
     * @brief The template to check if this class has a specific components
     * 
     * @return true if the component with said type exist on this class
     */
    template <typename T>
    bool Entity::hasComponent() const {
        type_index typeId = type_index(typeid(T));
        return m_components.count(typeId) > 0;
    }

}
