#pragma once

#include <memory>
#include <unordered_map>
#include <string>

#include "retronomicon/lib/core/scene.h"

namespace retronomicon::lib::core {

    class SceneManager {
    public:
        void registerScene(const std::string& name, std::shared_ptr<Scene> scene);
        std::shared_ptr<Scene> getScene(const std::string& name) const;

        std::shared_ptr<Scene> changeScene(const std::string& name);
        std::shared_ptr<Scene> getCurrentScene() const;

    private:
        std::unordered_map<std::string, std::shared_ptr<Scene>> m_scenes;
        std::shared_ptr<Scene> m_currentScene = nullptr;
    };

}
