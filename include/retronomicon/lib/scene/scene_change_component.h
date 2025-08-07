#pragma once

#include <string>

#include "retronomicon/lib/core/component.h"
namespace retronomicon::lib::scene {
    using retronomicon::lib::core::Component;

    /**
     * @brief A component that marks an entity to request a scene transition.
     * 
     * When `triggered` becomes true, the scene transition system can act on it.
     */
    struct SceneChangeComponent : public Component {
        std::string next_scene;
        bool triggered = false;

        SceneChangeComponent() = default;
        SceneChangeComponent(const std::string& scene)
            : next_scene(scene), triggered(false) {}
    };

}
