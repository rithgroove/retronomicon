#include "retronomicon/lib/core/scene_manager.h"

namespace retronomicon::lib::core {

    void SceneManager::registerScene(const std::string& name, std::shared_ptr<Scene> scene) {
        m_scenes[name] = scene;
    }

    std::shared_ptr<Scene> SceneManager::getScene(const std::string& name) const {
        auto it = m_scenes.find(name);
        return it != m_scenes.end() ? it->second : nullptr;
    }

    std::shared_ptr<Scene> SceneManager::changeScene(const std::string& name) {
        auto scene = getScene(name);
        if (!scene) return nullptr;

        if (!scene->isInitialized()) {
            scene->init();
        } else if (scene->requiresReset()) {
            scene->reset();
        }

        m_currentScene = scene;
        return m_currentScene;
    }

    std::shared_ptr<Scene> SceneManager::getCurrentScene() const {
        return m_currentScene;
    }

}
