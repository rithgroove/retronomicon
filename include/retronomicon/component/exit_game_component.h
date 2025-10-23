#pragma once

#include "retronomicon/component/component.h"   // your base Component class

/**
 * @brief The namespace for the core engine features of retronomicon
 */
namespace retronomicon::component {
    using retronomicon::component::Component;
    /**
     * @brief Component to signal that the game should exit.
     * 
     * Attach this to an Entity (e.g., a menu button) to indicate
     * that selecting/triggering it should exit the game.
     */
    class ExitGameComponent : public Component {
    public:
        /***************************** Constructor *****************************/

        /**
         * @brief default constructor
         */
        ExitGameComponent() = default;

        /***************************** Destructor *****************************/

        /**
         * @brief default desstructor
         */
        virtual ~ExitGameComponent() = default;

        /***************************** Getter *****************************/

        /**
         * @brief Whether this component has been activated (e.g., user pressed the button).
         */
        [[nodiscard]] bool isActivated() const noexcept { return m_activated; }

        /***************************** Setter *****************************/

        /**
         * @brief Activate the exit signal.
         */
        void activate() noexcept { m_activated = true; }

        /**
         * @brief Reset the activation state.
         */
        void reset() noexcept { m_activated = false; }

    private:
        /***************************** Attribute *****************************/
        bool m_activated = false;
    };

} // namespace retronomicon::lib::core
