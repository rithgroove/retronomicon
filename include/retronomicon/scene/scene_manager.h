#pragma once

#include <memory>
#include <unordered_map>
#include <string>

#include <retronomicon/scene/scene.h>

namespace retronomicon::scene {

class SceneManager {
public:
    SceneManager() = default;

    // Register a scene with a unique name
    void registerScene(const std::string& name, std::shared_ptr<Scene> scene);

    // Retrieve a registered scene by name
    std::shared_ptr<Scene> getScene(const std::string& name) const;

    // Switch the active scene (calls shutdown/start appropriately)
    std::shared_ptr<Scene> changeScene(const std::string& name);

    // Retrieve the current active scene
    std::shared_ptr<Scene> getCurrentScene() const;

private:
    std::unordered_map<std::string, std::shared_ptr<Scene>> m_scenes;
    std::shared_ptr<Scene> m_currentScene = nullptr;
};

} // namespace retronomicon::scene
