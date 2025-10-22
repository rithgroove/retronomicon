#pragma once
#include <memory>
#include "retronomicon/entity/entity.h"
#include "retronomicon/component/component.h"  
#include "retronomicon/component/renderable.h"

/**
 * @brief The namespace for ECS libraries that will be the building blocks for the engine
 */
namespace retronomicon::manager {

using retronomicon::entity::Entity;
using retronomicon::component::Renderable;

/**
 * @brief Generic class that traverses entities and calls render() on renderable components.
 */
class RenderManager {
    public:
        /**
         * @brief Traverse an entity and its children, rendering any Renderable components.
         *
         * @param entity Weak pointer to the entity root.
         */
        virtual void render(std::weak_ptr<Entity> entity) {
            if (auto e = entity.lock()) {
                // Render components that are also Renderable
                for (auto& comp : e->getComponents()) {
                    if (auto renderable = dynamic_cast<Renderable*>(comp.get())) {
                        // renderable->render();
                    }
                }

                // Recurse into children
                for (auto& child : e->getChildren()) {
                    render(child);
                }
            }
        }
};

} // namespace retronomicon::manager
