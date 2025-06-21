#include "retronomicon/lib/core/system/render_system.h"

namespace retronomicon::lib::core::system{
    RenderSystem::RenderSystem( SDL_Renderer* renderer) {
        m_renderer = renderer;
    }

    void RenderSystem::render(const vector<GameObject*>& objects) override {
        for (GameObject& obj : objects) {
            // render logic
            render.render(m_renderer);
        }
    }
}