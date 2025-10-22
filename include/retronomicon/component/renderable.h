#pragma once
#include "retronomicon/core/graphics/renderer/i_renderer.h"
/**
 * @brief The namespace for ECS libraries that will be the building blocks for the engine
 */
namespace retronomicon::component{
    /**
     * @brief Optional interface for components that can be rendered.
     */
    class Renderable {
        public:

            virtual ~Renderable() = default;
            /**
             * @brief Called when rendering
             */
            virtual void Render(retronomicon::graphics::IRenderer& renderer) = 0;

            bool isVisible() {return m_isVisible;}

            void hide(){m_isVisible = false;}

            void show(){m_isVisible = true;}
        private:

            bool m_isVisible = true;
    };

} // namespace retronomicon::core::ecs
