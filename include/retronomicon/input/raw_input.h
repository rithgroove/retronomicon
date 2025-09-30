#pragma once

#include <vector>
#include <memory>
#include <string>

namespace retronomicon::input {

    /**
     * @brief Abstract interface for raw input backends.
     * 
     * Provides a unified way to poll events, query keyboard, mouse, or controller state.
     * Platform-specific backends (e.g., SDL, GLFW) will implement this.
     */
    class RawInput {
    public:
        virtual ~RawInput() = default;

        /**
         * @brief Poll for input events and update internal state.
         */
        virtual void poll() = 0;

        /**
         * @brief Clear stored events.
         */
        virtual void clear() = 0;

        /**
         * @brief Retrieve raw events (backend-specific identifiers).
         * 
         * @return List of events in a generic form (could be strings, IDs, or a thin wrapper).
         */
        virtual const std::vector<std::string>& getEvents() const = 0;

        /**
         * @brief Query keyboard state.
         * 
         * @param keyCode Engine-agnostic KeyCode identifier.
         * @return True if pressed, false otherwise.
         */
        virtual bool isKeyPressed(int keyCode) const = 0;

        /**
         * @brief Get mouse position.
         */
        virtual int getMouseX() const = 0;
        virtual int getMouseY() const = 0;

        /**
         * @brief Get current mouse button bitmask.
         */
        virtual unsigned int getMouseButtons() const = 0;
    };

} // namespace retronomicon::lib::input
