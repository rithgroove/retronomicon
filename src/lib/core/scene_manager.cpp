#include "retronomicon/lib/core/scene_manager.h"

// Replace these with your real scene headers
#include "retronomicon/lib/platformer/scenes/splash_scene.h"
#include "retronomicon/lib/platformer/scenes/menu_scene.h"
#include "retronomicon/lib/platformer/scenes/level_scene.h"

namespace retronomicon::lib::core {

    std::shared_ptr<Scene> SceneManager::createSplashScene() {
        return std::make_shared<retronomicon::lib::platformer::SplashScene>();
    }

    std::shared_ptr<Scene> SceneManager::createMenuScene() {
        return std::make_shared<retronomicon::lib::platformer::MenuScene>();
    }

    std::shared_ptr<Scene> SceneManager::createLevelScene(const std::string& levelName) {
        return std::make_shared<retronomicon::lib::platformer::LevelScene>(levelName);
    }

    void SceneManager::registerScene(const std::string& name, std::shared_ptr<Scene> scene) {
        m_scenes[name] = scene;
    }

    std::shared_ptr<Scene> SceneManager::getScene(const std::string& name) const {
        auto it = m_scenes.find(name);
        if (it != m_scenes.end()) {
            return it->second;
        }
        return nullptr;
    }

}
