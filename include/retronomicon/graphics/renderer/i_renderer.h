

#pragma once
/**
 * @brief Defines the IRenderer interface for graphics backends.
 *
 * This interface abstracts the rendering layer so that different graphics APIs
 * (e.g., SDL, OpenGL, Vulkan) can be used interchangeably within the engine.
 * Implementations of this interface are responsible for initializing the graphics
 * backend, performing rendering, and releasing resources on shutdown.
 */
namespace retronomicon::graphics::renderer {

    /**
     * @brief Abstract interface for all rendering backends.
     *
     * The IRenderer class defines the lifecycle and rendering responsibilities
     * of a graphics backend. Concrete implementations must provide initialization,
     * rendering, and shutdown logic for their specific API.
     */
    class IRenderer {
    public:
        /**
         * @brief Initialize the renderer.
         *
         * Called once before rendering begins. 
         * Implementations should allocate resources, create contexts,
         * and prepare the backend for rendering.
         */
        virtual void init() = 0;

        /**
         * @brief Perform rendering operations.
         *
         * Called every frame to issue draw commands and present
         * graphics to the screen. The exact behavior depends on the
         * underlying graphics API.
         */
        virtual void render() = 0;

        /**
         * @brief Shutdown the renderer and release resources.
         *
         * Called once when the renderer is no longer needed. Implementations
         * must free memory, destroy contexts, and clean up any allocated
         * graphics resources.
         */
        virtual void shutdown() = 0;

        /**
         * @brief Virtual destructor.
         *
         * Ensures proper cleanup when deleting derived renderer objects
         * through a base class pointer.
         */
        virtual ~IRenderer() = default;
    };

} // namespace retronomicon::graphics::renderer
