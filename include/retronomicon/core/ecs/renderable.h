#pragma once

#include "retronomicon/lib/math/rect.h"
/**
 * @brief The namespace for ECS libraries that will be the building blocks for the engine
 */
namespace retronomicon::core::ecs{
    using retronomicon::lib::math::Rect;
    /**
     * @brief Optional interface for components that can be rendered.
     */
    class Renderable {
        public:

            /**
             * @brief Called when rendering with SDL
             */
            virtual void render() = 0;

            /**
             * @brief method to calculate the size of the rendered component
             * 
             * @return size in rectangle format
             */
            virtual Rect getSize() = 0;
    };

} // namespace retronomicon::core::ecs
