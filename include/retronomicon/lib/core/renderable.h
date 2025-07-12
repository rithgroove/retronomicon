#pragma once

#include <SDL.h>

namespace retronomicon::lib::core {

    /**
     * @brief Optional interface for components that render with SDL.
     */
    class Renderable {
    public:
        virtual ~Renderable() = default;

        /**
         * @brief Called when rendering with SDL
         */
        virtual void render(SDL_Renderer* renderer) = 0;
    };

} // namespace retronomicon::lib::core
