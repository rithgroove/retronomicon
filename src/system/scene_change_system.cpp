#include "retronomicon/system/scene_change_system.h"// or wherever Engine is defined
#include "retronomicon/scene/scene.h"
#include <iostream>

namespace retronomicon::system{
    using retronomicon::scene::Scene;

    void SceneChangeSystem::update(float dt, std::weak_ptr<Entity> entity) {
        if (auto e = entity.lock()) {
            auto sceneChange = e->getComponent<SceneChangeComponent>();
            if (sceneChange && sceneChange->isTriggered()) {
                // get current scene before change
                std::shared_ptr<Scene> currentScene = m_engine->getCurrentScene();

                // change the scene first so the pointer is to the new scene
                if (m_engine) {
                    m_engine->changeScene(sceneChange->getNextScene());
                }

                // now shutdown because it's not used by engine
                currentScene->shutdown();
            }

            // Recurse through children
            for (auto& child : e->getChildren()) {
                update(dt, child);
            }
        }
    }

}
