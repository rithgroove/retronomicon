#pragma once

#include <SDL.h>
#include <vector>

#include "retronomicon/lib/core/system.h"

namespace retronomicon::lib::graphic {

    class RenderSystem : public core::System {
    public:
        explicit RenderSystem(SDL_Renderer* renderer);

        void render(core::Entity* entity) override;

    private:
        SDL_Renderer* m_renderer;
    };

} // namespace retronomicon::lib::graphic
