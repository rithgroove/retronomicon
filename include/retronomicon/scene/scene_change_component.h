#pragma once
#include <string>

namespace retronomicon::core::ecs {

    struct SceneChangeComponent {
        std::string nextSceneId;
        bool triggered = false;

        explicit SceneChangeComponent(const std::string& next)
            : nextSceneId(next)
        {}

        void trigger() { triggered = true; }
    };

} // namespace retronomicon::core::ecs
