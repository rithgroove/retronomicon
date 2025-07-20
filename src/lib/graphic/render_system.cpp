#include "retronomicon/lib/graphic/render_system.h"
#include "retronomicon/lib/graphic/sprite_component.h"

namespace retronomicon::lib::graphic {

    using retronomicon::lib::core::Entity;

    RenderSystem::RenderSystem(SDL_Renderer* renderer)
        : m_renderer(renderer) {}

    void RenderSystem::render(std::vector<Entity*>& objects) {
        for (Entity* obj : objects) {
            auto sprite = obj->getComponent<SpriteComponent>();
            if (!sprite) continue;
            sprite->render(m_renderer);
        }
    }

} // namespace retronomicon::lib::graphic
