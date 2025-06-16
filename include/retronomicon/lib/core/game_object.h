#pragma once

#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include <memory>

#include "component.h"

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::core{
    class GameObject {
        public:
            GameObject();
            ~GameObject();

            void start();
            void update(float dt);
            void render();

            template <typename T, typename... Args>
            T* addComponent(Args&&... args);

            template <typename T>
            T* getComponent();

        private:
            std::unordered_map<std::type_index, std::unique_ptr<Component>> components;
    };

    // ---------- Template definitions ----------

    template <typename T, typename... Args>
    T* GameObject::addComponent(Args&&... args) {
        std::type_index typeId = std::type_index(typeid(T));
        if (components.count(typeId) == 0) {
            T* rawPtr = new T(std::forward<Args>(args)...);
            rawPtr->setOwner(this);
            components[typeId] = std::unique_ptr<Component>(rawPtr);
            return rawPtr;
        }
        return nullptr;
    }

    template <typename T>
    T* GameObject::getComponent() {
        std::type_index typeId = std::type_index(typeid(T));
        auto it = components.find(typeId);
        if (it != components.end()) {
            return static_cast<T*>(it->second.get());
        }
        return nullptr;
    }
}
