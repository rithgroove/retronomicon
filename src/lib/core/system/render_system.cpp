#include "retronomicon/lib/core/system/render_system.h"

namespace retronomicon::lib::core::system{
    RenderSystem::RenderSystem( SDL_Renderer* renderer) {
        m_renderer = renderer;
    }

    void RenderSystem::render(const vector<shared_ptr<GameObject>>& objects) override {
        for (auto& obj : objects) {
            // render logic
            obj.redner(m_renderer);
        }
    }
}