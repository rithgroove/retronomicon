#pragma once
#include <string>

#include <iostream>
#include "component.h"

namespace retronomicon::component {

    /**
     * @brief Signals the engine to switch to another scene.
     *
     * This component is typically consumed by a `SceneChangeSystem`.
     * When `trigger()` is called, the system:
     *  - reads the target scene name,
     *  - instructs the `SceneManager` to load or reset that scene,
     *  - clears or reuses this component depending on game logic.
     *
     * Use cases:
     *  - Player enters a door / portal.
     *  - UI button requests scene transition.
     *  - Cutscene or script triggers a scene load.
     */
    class SceneChangeComponent : public Component {
    public:
        /**
         * @brief Construct with the name of the scene to switch to.
         *
         * @param next Name of the target scene.
         */
        explicit SceneChangeComponent(const std::string& next)
            : m_nextScene(next)
        {}

        /**
         * @brief Update the target scene name.
         *
         * @param nextScene New scene identifier.
         */
        void setNextScene(const std::string& nextScene) {
            m_nextScene = nextScene;
        }

        /**
         * @brief Mark this component as requesting a scene change.
         */
        void trigger() { m_triggered = true; }

        /**
         * @brief Clear the trigger flag after the scene system processes it.
         */
        void resetTrigger() { m_triggered = false; }

        /**
         * @brief Get the name of the target scene.
         *
         * @return Const reference to the stored scene name.
         */
        const std::string& getNextScene() const {
            return m_nextScene;
        }

        /**
         * @brief Check whether a scene change was requested.
         */
        bool isTriggered() const { return m_triggered; }

    private:
        std::string m_nextScene; ///< Name of the scene that should be loaded.
        bool m_triggered = false; ///< True when a transition has been triggered.
    };

} // namespace retronomicon::component
