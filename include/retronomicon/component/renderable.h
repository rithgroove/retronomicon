#pragma once
#include "retronomicon/graphics/renderer/i_renderer.h"
#include <memory>

/**
 * @brief ECS component utilities for the Retronomicon engine.
 */
namespace retronomicon::component {

    using retronomicon::graphics::renderer::IRenderer;

    /**
     * @class Renderable
     * @brief Interface for components capable of being rendered.
     *
     * This interface allows an ECS component to participate in the rendering
     * pipeline. Any component inheriting from Renderable must implement the
     * render() method, which is invoked by the rendering system each frame.
     *
     * Visibility can be toggled using show() and hide(), allowing systems to
     * render or skip components without removing them from the ECS structure.
     */
    class Renderable {
    public:
        /**
         * @brief Virtual destructor for safe polymorphic cleanup.
         */
        virtual ~Renderable() = default;

        /**
         * @brief Render the component.
         *
         * Implementations should use the provided renderer to draw themselves.
         *
         * @param renderer Shared pointer to the active renderer.
         */
        virtual void render(std::shared_ptr<IRenderer> renderer) = 0;

        /**
         * @brief Check if the component is currently visible.
         * @return true if visible, false if hidden.
         */
        bool isVisible() { return m_isVisible; }

        /**
         * @brief Hide the component from rendering.
         *
         * The component remains active in ECS but will be skipped during rendering.
         */
        void hide() { m_isVisible = false; }

        /**
         * @brief Show the component during rendering.
         */
        void show() { m_isVisible = true; }

    private:
        /**
         * @brief Whether the component should be rendered.
         *
         * The rendering system checks this flag before invoking render().
         */
        bool m_isVisible = true;
    };

} // namespace retronomicon::component
