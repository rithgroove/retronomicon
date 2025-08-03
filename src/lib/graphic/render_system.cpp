#include "retronomicon/lib/graphic/render_system.h"
#include "retronomicon/lib/graphic/sprite_component.h"
#include <iostream>
namespace retronomicon::lib::graphic {

    using retronomicon::lib::core::Entity;

    RenderSystem::RenderSystem(SDL_Renderer* renderer)
        : m_renderer(renderer) {}

    void RenderSystem::render(Entity* entity) {
        auto sprite = entity->getComponent<SpriteComponent>();
        if (sprite){
            std::cout<<"Ketemu Sprite"<<std::endl;            
            sprite->render(m_renderer);
        }

        for (Entity* obj : entity->m_childEntities) {
            this->render(obj);
        }
    }

} // namespace retronomicon::lib::graphic
