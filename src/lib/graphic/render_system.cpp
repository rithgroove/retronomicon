#include "retronomicon/lib/graphic/render_system.h"
#include "retronomicon/lib/graphic/sprite_component.h"
#include <iostream>
namespace retronomicon::lib::graphic {

    using retronomicon::lib::core::Entity;

    RenderSystem::RenderSystem(SDL_Renderer* renderer)
        : m_renderer(renderer) {}

    void RenderSystem::render(Entity* entity) {

        if (entity->isVisible()){
            for (auto& component : entity->getComponents()) {
                if (auto renderable = dynamic_cast<Renderable*>(component)) {
                    renderable->render(m_renderer);
                }
            }            
        }

        for (Entity* obj : entity->getChilds()) {
            this->render(obj);
        }
    }

} // namespace retronomicon::lib::graphic
