#include "system.h"

namespace retronomicon::lib::core::system{
    class RenderSystem : public System {
        public:
            RenderSystem::RenderSystem( SDL_Renderer* renderer);

            void render(const vector<GameObject*>& objects) override;

        private:
            SDL_Renderer* m_renderer;
    };
}