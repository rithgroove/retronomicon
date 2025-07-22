#include "retronomicon/lib/core/scene_change_system.h"

namespace retronomicon::lib::core::system {

    void SceneChangeSystem::update(float, std::vector<Entity*>& entities) {
        for (Entity* entity : entities) {
            if (entity->hasComponent<SceneChangeComponent>()) {
                auto* sceneChange = entity->getComponent<SceneChangeComponent>();
                m_engine->changeScene(sceneChange->next_scene);
                break; // optional: change once per frame
            }
        }
    }

}
