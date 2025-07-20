#include "retronomicon/lib/core/system/scene_change_system.h"

namespace retronomicon::lib::core::system {

    void SceneChangeSystem::update(float, std::vector<GameObject*>& objects) {
        for (GameObject* obj : objects) {
            if (!obj->has<ChangeSceneComponent>()) continue;

            auto& changeScene = obj->get<ChangeSceneComponent>();
            if (changeScene.triggered) {
                // Clear flag to avoid double trigger
                changeScene.triggered = false;

                // Request scene change via engine
                m_engine->requestSceneChange(changeScene.next_scene);

                // Optional: break if scene change should stop everything else
                break;
            }
        }
    }

}
