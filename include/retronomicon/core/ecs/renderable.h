#pragma once

/**
 * @brief The namespace for ECS libraries that will be the building blocks for the engine
 */
namespace retronomicon::core::ecs{
    /**
     * @brief Optional interface for components that can be rendered.
     */
    class Renderable {
        public:

            /**
             * @brief Called when rendering
             */
            virtual void render() = 0;
    };

} // namespace retronomicon::core::ecs
