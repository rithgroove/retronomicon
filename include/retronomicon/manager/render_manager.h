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
    using retronomicon::graphics::renderer::IRenderer;
    /**
     * @brief Generic class that traverses entities and calls render() on renderable components.
     */
    class RenderManager {
        public:
            RenderManager(std::shared_ptr<IRenderer> renderer);

            /**
             * @brief Traverse an entity and its children, rendering any Renderable components.
             *
             * @param entity Weak pointer to the entity root.
             */
            virtual void render(std::weak_ptr<Entity> entity);
        private:

            std::shared_ptr<IRenderer> m_renderer;
    };

} // namespace retronomicon::manager
