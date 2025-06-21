#include "system.h"

namespace retronomicon::lib::core::system{
    class RenderSystem : public System {
        public:
            RenderSystem( SDL_Renderer* renderer);

            void render(vector<GameObject*>& objects) override;

        private:
            SDL_Renderer* m_renderer;
    };
}