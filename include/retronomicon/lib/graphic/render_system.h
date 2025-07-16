#pragma once
#include <SDL.h>
#include "retronomicon/lib/core/system.h"

namespace retronomicon::lib::graphic{
    class RenderSystem : public retronomicon::lib::core::System {
        public:
            RenderSystem( SDL_Renderer* renderer);

            void render(vector<retronomicon::lib::core::GameObject*>& objects) override;

        private:
            SDL_Renderer* m_renderer;
    };
}