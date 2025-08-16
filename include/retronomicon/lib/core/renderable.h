#pragma once

#include <SDL.h>
#include "retronomicon/lib/math/rect.h"
namespace retronomicon::lib::core {
    using retronomicon::lib::math::Rect;
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

        virtual Rect getSize() = 0;
    };

} // namespace retronomicon::lib::core
