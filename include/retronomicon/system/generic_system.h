#pragma once
#include <memory>
#include "entity.h"
#include "component.h"
#include "system.h"
/**
 * @brief The namespace for ECS libraries that will be the building blocks for the engine
 */
namespace retronomicon::system {
    /**
     * @brief generic class that loops all specified component and calls update
     */
    template <typename T>
    class GenericSystem: public System {
        static_assert(std::is_base_of<Component, T>::value,
                      "System<T> requires T to derive from Component");
        public:
            using ComponentType = T;

        /**
         * @brief update method. traverse all entity and trigger update on the specified component
         *
         * @param dt float delta time since last update
         * @param entity weak_ptr to the entity
         */
        virtual void update(float dt, std::weak_ptr<Entity> entity) {
            if (auto e = entity.lock()) {
                auto comp = e->getComponent<T>();
                if (comp) {
                    comp->update(dt);  // always valid now
                }

                for (auto& child : e->getChildren()) {
                    update(dt, child);
                }
            }
        }
    };
}
