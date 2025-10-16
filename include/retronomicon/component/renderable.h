#pragma once

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
            virtual void render() = 0;
    };

} // namespace retronomicon::core::ecs
