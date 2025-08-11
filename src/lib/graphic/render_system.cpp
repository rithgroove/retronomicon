#include "retronomicon/lib/graphic/render_system.h"
#include "retronomicon/lib/graphic/sprite_component.h"
#include <iostream>
namespace retronomicon::lib::graphic {

    using retronomicon::lib::core::Entity;

    RenderSystem::RenderSystem(SDL_Renderer* renderer)
        : m_renderer(renderer) {}

    void RenderSystem::render(Entity* entity) {

        std::cout<< "[Render System] test render di scene cpp : "<< entity->getName() << std::endl;
        for (auto& component : entity->getComponents()) {
            if (auto renderable = dynamic_cast<Renderable*>(component)) {
                std::cout<< "[Render System] ketemu renderable : "<< entity->getName() << std::endl;
                renderable->render(m_renderer);
            }
        }
        for (Entity* obj : entity->getChilds()) {
            this->render(obj);
        }
    }

} // namespace retronomicon::lib::graphic
