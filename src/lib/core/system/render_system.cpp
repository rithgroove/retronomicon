#include "retronomicon/lib/core/system/render_system.h"

namespace retronomicon::lib::core::system{
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