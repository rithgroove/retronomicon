#include "retronomicon/manager/render_manager.h"
#include <iostream>
/**
 * @brief The namespace for ECS libraries that will be the building blocks for the engine
 */
namespace retronomicon::manager {
	RenderManager::RenderManager(std::shared_ptr<IRenderer> renderer): m_renderer(renderer){
	}

    void RenderManager::render(std::weak_ptr<Entity> entity) {
        if (auto e = entity.lock()) {
            // Render components that are also Renderable
            for (auto& comp : e->getComponents()) {
                if (auto renderable = dynamic_cast<Renderable*>(comp.get())) {
                    renderable->render(m_renderer);
                    // renderable->render();
                }
            }

            // Recurse into children
            for (auto& child : e->getChildren()) { 
                render(child);
            }
        }
    }
}