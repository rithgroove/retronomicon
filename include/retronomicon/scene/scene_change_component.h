#pragma once
#include <string>

namespace retronomicon::core::ecs {

    class SceneChangeComponent {
        public:
            explicit SceneChangeComponent(const std::string& next)
                : m_nextScene(next)
            {}

            // Take const reference to avoid unnecessary copy
            void setNextScene(const std::string& nextScene) {
                m_nextScene = nextScene;
            }

            void trigger() { m_triggered = true; }
            void resetTrigger() { m_triggered = false; }

            // Mark as const since it doesn't modify state
            const std::string& getNextScene() const {
                return m_nextScene;
            }

            bool isTriggered() const { return m_triggered; }

        private:
            std::string m_nextScene;
            bool m_triggered = false;
    };

} // namespace retronomicon::core::ecs
