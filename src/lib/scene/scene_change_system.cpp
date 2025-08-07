#include "retronomicon/lib/scene/scene_change_system.h"
#include <iostream>
namespace retronomicon::lib::scene {

    void SceneChangeSystem::update(float dt,Entity* entity) {
        std::cout<< "test1 : "<< entity->getName() << std::endl;
        auto* sceneChange = entity->getComponent<SceneChangeComponent>();
        if (sceneChange && sceneChange->triggered){
            m_engine->changeScene(sceneChange->next_scene);
            sceneChange->triggered = false;
        }

        for (Entity* child : entity->m_childEntities) {
            std::cout<< "test2 child : "<< entity->getName() << std::endl;
            this->update(dt, child);
        }
    }

}
