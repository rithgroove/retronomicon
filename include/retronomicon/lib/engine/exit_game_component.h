#pragma once

#include "retronomicon/lib/core/component.h"   // your base Component class

namespace retronomicon::lib::engine {
    using retronomicon::lib::core::Component;
    /**
     * @brief Component to signal that the game should exit.
     * 
     * Attach this to an Entity (e.g., a menu button) to indicate
     * that selecting/triggering it should exit the game.
     */
    class ExitGameComponent : public Component {
    public:
        ExitGameComponent();
        virtual ~ExitGameComponent();

        /**
         * @brief Whether this component has been activated (e.g., user pressed the button).
         */
        bool isActivated() const;

        /**
         * @brief Activate the exit signal.
         */
        void activate();

        /**
         * @brief Reset the activation state.
         */
        void reset();

    private:
        bool m_activated;
    };

} // namespace retronomicon::lib::core
