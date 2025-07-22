#pragma once

#include <memory>
#include <unordered_map>
#include <string>

#include "retronomicon/lib/core/scene.h"

namespace retronomicon::lib::core {

    class SceneManager {
    public:
        // Factory methods
        // static std::shared_ptr<Scene> createSplashScene();
        // static std::shared_ptr<Scene> createMenuScene();
        // static std::shared_ptr<Scene> createLevelScene(const std::string& levelName);

        // Optional registry (future-proofing)
        void registerScene(const std::string& name, std::shared_ptr<Scene> scene);
        std::shared_ptr<Scene> getScene(const std::string& name) const;

    private:
        std::unordered_map<std::string, std::shared_ptr<Scene>> m_scenes;
    };

}
