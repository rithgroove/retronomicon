#include "retronomicon/lib/core/system/render_system.h"
#include "retronomicon/lib/core/component/sprite_component.h"

namespace retronomicon::lib::core::system{
    using retronomicon::lib::core::component::SpriteComponent;
    RenderSystem::RenderSystem( SDL_Renderer* renderer) {
        m_renderer = renderer;
    }

    void RenderSystem::render(vector<GameObject*>& objects) {
        for (GameObject* obj : objects) {
            // render logic
            auto sprite = obj->getComponent<SpriteComponent>();
            if (!sprite) continue;
            sprite->render(m_renderer);
        }

    }
}