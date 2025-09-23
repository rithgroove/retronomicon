#pragma once

#include <string>

#pragma once

#include <string>

namespace retronomicon::graphics {

/**
 * @brief Abstract interface for a generic game/application window.
 *
 * Provides base functionality such as title and size tracking, while concrete
 * backends (SDL, OpenGL, Vulkan, etc.) handle platform-specific details like
 * window creation and rendering contexts.
 */
    class IWindow {
        public:
            /**
             * @brief Construct a new IWindow object.
             *
             * @param title   The title of the window.
             * @param width   The initial width of the window (in pixels).
             * @param height  The initial height of the window (in pixels).
             */
            IWindow(const std::string& title, int width, int height)
                : m_title(title), m_width(width), m_height(height) {}

            /**
             * @brief Virtual destructor.
             *
             * Ensures proper cleanup when deleting through an IWindow pointer.
             */
            virtual ~IWindow() = default;

            // ------------------------------------------------------------------------
            // Accessors
            // ------------------------------------------------------------------------

            /**
             * @brief Get the current width of the window.
             *
             * @return The width in pixels.
             */
            virtual int getWidth() const { return m_width; }

            /**
             * @brief Get the current height of the window.
             *
             * @return The height in pixels.
             */
            virtual int getHeight() const { return m_height; }

            /**
             * @brief Get the current title of the window.
             *
             * @return The window title as a string.
             */
            virtual std::string getTitle() const { return m_title; }

            // ------------------------------------------------------------------------
            // Mutators
            // ------------------------------------------------------------------------

            /**
             * @brief Set the window title.
             *
             * @param title The new title.
             */
            virtual void setTitle(const std::string& title) { m_title = title; }

            /**
             * @brief Handle a resize event.
             *
             * Updates the stored width and height. Concrete backends may extend this
             * to reconfigure swapchains, framebuffers, etc.
             *
             * @param newWidth   New width in pixels.
             * @param newHeight  New height in pixels.
             */
            virtual void handleResize(int newWidth, int newHeight) {
                m_width = newWidth;
                m_height = newHeight;
            }

            // ------------------------------------------------------------------------
            // Pure virtuals (must be implemented by backend)
            // ------------------------------------------------------------------------

            /**
             * @brief Query whether the window is currently in fullscreen mode.
             *
             * @return true if the window is fullscreen, false otherwise.
             */
            virtual bool isFullscreen() const = 0;

            /**
             * @brief Toggle the fullscreen state of the window.
             *
             * Backends are responsible for handling the platform-specific details.
             */
            virtual void toggleFullscreen() = 0;

        protected:
            /// Title of the window.
            std::string m_title;

            /// Current width of the window (pixels).
            int m_width;

            /// Current height of the window (pixels).
            int m_height;
    };

} // namespace retronomicon::graphics

