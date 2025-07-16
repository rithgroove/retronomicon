#pragma once

#include <SDL.h>
#include <vector>

#include "retronomicon/lib/core/system.h"
#include "retronomicon/lib/core/game_object.h"

namespace retronomicon::lib::graphic {

    class RenderSystem : public core::System {
    public:
        explicit RenderSystem(SDL_Renderer* renderer);

        void render(std::vector<core::GameObject*>& objects) override;

    private:
        SDL_Renderer* m_renderer;
    };

} // namespace retronomicon::lib::graphic
