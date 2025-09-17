#pragma once
#include <memory>
#include "entity.h"
#include "renderable.h"

/**
 * @brief The namespace for ECS libraries that will be the building blocks for the engine
 */
namespace retronomicon::core::ecs {

    /**
     * @brief Generic class that traverses entities and calls render() on renderable components.
     */
    class Renderer {
        public:
            /**
             * @brief Traverse an entity and its children, rendering any Renderable components.
             *
             * @param entity Weak pointer to the entity root.
             */
            virtual void render(std::weak_ptr<Entity> entity) {
                if (auto e = entity.lock()) {  // upgrade weak_ptr to shared_ptr
                    // Render components of this entity
                    for (auto& comp : e->getComponents()) {
                        if (auto renderable = std::dynamic_pointer_cast<Renderable>(comp)) {
                            renderable->render();
                        }
                    }

                    // Recurse into children
                    for (auto& child : e->getChildren()) {
                        render(child);
                    }
                }
            }
    };
}
