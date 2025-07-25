#include "retronomicon/lib/core/scene_change_system.h"

namespace retronomicon::lib::core {

    void SceneChangeSystem::update(float, std::vector<Entity*>& entities) {
        for (Entity* entity : entities) {
            if (entity->hasComponent<SceneChangeComponent>()) {                
                auto* sceneChange = entity->getComponent<SceneChangeComponent>();
                if (sceneChange->triggered){
                    m_engine->changeScene(sceneChange->next_scene);
                }
                break; // optional: change once per frame
            }
        }
    }

}
