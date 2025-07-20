#pragma once

#include <string>

namespace retronomicon::lib::core::component {

    /**
     * @brief A component that marks an entity to request a scene transition.
     * 
     * When `triggered` becomes true, the scene transition system can act on it.
     */
    struct ChangeSceneComponent {
        std::string next_scene;
        bool triggered = false;

        ChangeSceneComponent() = default;
        ChangeSceneComponent(const std::string& scene)
            : next_scene(scene), triggered(false) {}
    };

}
