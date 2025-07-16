#pragma once

#include <SDL_rect.h>
#include "retronomicon/lib/math/rect.h"

namespace retronomicon::lib::graphic::internal {

    /**
     * @brief Converts a math::Rect to an SDL_Rect.
     * 
     * @param rect The rectangle from the math namespace.
     * @return SDL_Rect representation for rendering.
     */
    inline SDL_Rect toSDLRect(const retronomicon::lib::math::Rect& rect) {
        return SDL_Rect{
            static_cast<int>(rect.getX()),
            static_cast<int>(rect.getY()),
            static_cast<int>(rect.getWidth()),
            static_cast<int>(rect.getHeight())
        };
    }

} // namespace retronomicon::lib::graphic::internal
