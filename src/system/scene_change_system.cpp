#include "retronomicon/system/scene_change_system.h"// or wherever Engine is defined
#include <iostream>

namespace retronomicon::system{

    void SceneChangeSystem::update(float dt, std::weak_ptr<Entity> entity) {
        if (auto e = entity.lock()) {
            auto sceneChange = e->getComponent<SceneChangeComponent>();
            if (sceneChange && sceneChange->isTriggered()) {
                std::cout << "[SceneChangeSystem] next_scene: "
                          << sceneChange->getNextScene() << std::endl;

                if (m_engine) {
                    m_engine->changeScene(sceneChange->getNextScene());
                }

                sceneChange->resetTrigger();
            }

            // Recurse through children
            for (auto& child : e->getChildren()) {
                update(dt, child);
            }
        }
    }

}
