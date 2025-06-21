#pragma once

#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include <memory>
#include <string>
#include "retronomicon/lib/core/component/component.h"

using namespace std;
using namespace retronomicon::lib::core::component;
/**
 * @brief The namespace for core libraries such as game object and components
 */
namespace retronomicon::lib::core{
    class GameObject {
        public:
            /**
             * @brief empty constructor 
             */
            GameObject(const string& name);

            /**
             * @brief default destructor 
             */
            ~GameObject();

            /**
             * @brief start function (used to initialize stuff)
             */
            void start();

            /**
             * @brief method to update the component
             * 
             * @param dt time interval since last update
             */
            void update(float dt);

            /**
             * @brief a method to render the component if any
             */
            void render();


            /**
             * @brief a method to add components. this will use templates
             * 
             * @param args the component 
             */
            template <typename T, typename... Args>
            T* addComponent(Args&&... args);

            /**
             * @brief a method to return a components with a specific types
             * 
             * @return the component 
             */
            template <typename T>
            T* getComponent();

        private:
            unordered_map<type_index, unique_ptr<Component>> components;
            string m_name;
    };

    // ---------- Template definitions ----------

    template <typename T, typename... Args>
    T* GameObject::addComponent(Args&&... args) {
        type_index typeId = type_index(typeid(T));
        if (components.count(typeId) == 0) {
            T* rawPtr = new T(forward<Args>(args)...);
            rawPtr->setOwner(this);
            components[typeId] = unique_ptr<Component>(rawPtr);
            return rawPtr;
        }
        return nullptr;
    }

    template <typename T>
    T* GameObject::getComponent() {
        type_index typeId = type_index(typeid(T));
        auto it = components.find(typeId);
        if (it != components.end()) {
            return static_cast<T*>(it->second.get());
        }
        return nullptr;
    }
}
