#include "retronomicon/lib/scene/scene_change_system.h"

namespace retronomicon::lib::scene {

    void SceneChangeSystem::update(float dt,Entity* entity) {
        auto* sceneChange = entity->getComponent<SceneChangeComponent>();
        if (sceneChange->triggered){
            m_engine->changeScene(sceneChange->next_scene);
        }

        for (Entity* entity : entity->m_childEntities) {
            this->update(dt, entity);
        }
    }

}
