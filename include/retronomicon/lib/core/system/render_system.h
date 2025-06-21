#include "retronomicon/lib/core/system/render_system.h"

namespace retronomicon::lib::core::system{
    class RenderSystem : public System {
        public:
            RenderSystem::RenderSystem( SDL_Renderer* renderer);

            void render(const vector<shared_ptr<GameObject>>& objects) override {
                for (auto& obj : objects) {
                    // render logic
                    obj.redner(m_renderer);
                }
            }

        private:
            SDL_Renderer* m_renderer;
    };
}