#pragma once

#include <vector>
#include <string>
#include "retronomicon/input/key.h"

namespace retronomicon::input {

    /**
     * @brief Abstract interface for raw input backends.
     *
     * Provides a unified, backend-agnostic way to poll events,
     * query keyboard state, and read mouse state.
     *
     * Implementations:
     *   - SDLRawInput  (SDL backend)
     *   - GLFWRawInput (GLFW backend)
     */
    class RawInput {
    public:
        virtual ~RawInput() = default;

        /**
         * @brief Poll the underlying backend for new events
         *        and update cached state.
         */
        virtual void poll() = 0;

        /**
         * @brief Clear transient/raw events collected since last poll().
         */
        virtual void clear() = 0;

        /**
         * @brief Retrieve backend-agnostic event identifiers.
         *
         * For simple engines these may be strings.
         * In the future you can replace this with a custom Event struct.
         */
        virtual const std::vector<std::string>& getEvents() const = 0;

        /**
         * @brief Query if a specific key is currently pressed.
         *
         * @param key Engine-defined unified key enum.
         * @return true if pressed; false otherwise.
         */
        virtual bool isKeyPressed(Key key) const = 0;

        /**
         * @brief Get the current mouse cursor X position (in window coords).
         */
        virtual int getMouseX() const = 0;

        /**
         * @brief Get the current mouse cursor Y position (in window coords).
         */
        virtual int getMouseY() const = 0;

        /**
         * @brief Get current mouse button bitmask.
         *
         * Bit layout (for simplicity; shared across all backends):
         *   1 << 0  = left button
         *   1 << 1  = right button
         *   1 << 2  = middle button
         */
        virtual unsigned int getMouseButtons() const = 0;
    };

} // namespace retronomicon::input
