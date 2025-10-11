#include <retronomicon/scene/scene_change_system.h>// or wherever Engine is defined
#include <iostream>

using namespace retronomicon::scene;
using namespace retronomicon::core::ecs;

void SceneChangeSystem::update(float dt, std::weak_ptr<Entity> entity) {
    if (auto e = entity.lock()) {
        auto sceneChange = e->getComponent<SceneChangeComponent>();
        if (sceneChange && sceneChange->triggered) {
            std::cout << "[SceneChangeSystem] next_scene: "
                      << sceneChange->next_scene << std::endl;

            if (m_engine) {
                m_engine->changeScene(sceneChange->next_scene);
            }

            sceneChange->triggered = false;
        }

        // Recurse through children
        for (auto& child : e->getChildren()) {
            update(dt, child);
        }
    }
}
