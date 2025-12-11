#pragma once

#include <memory>
#include <unordered_map>
#include <string>

#include <retronomicon/scene/scene.h>

namespace retronomicon::scene {

    /**
     * @brief Manages all scenes in the engine and handles scene transitions.
     *
     * The SceneManager stores named scene instances and provides:
     *  - registering scenes (`registerScene`)
     *  - retrieving scenes (`getScene`)
     *  - switching scenes (`changeScene`)
     *  - storing the currently active scene
     *
     * Scene lifecycle expectations:
     *  - When switching scenes, the previous scene's `shutdown()` is called.
     *  - The new scene’s `start()` method is called before use.
     *  - If the same scene is requested twice, SceneManager may choose
     *    to skip reinitialization or reset the scene based on engine policy.
     */
    class SceneManager {
    public:
        SceneManager() = default;

        /**
         * @brief Register a scene with a unique string identifier.
         *
         * @param name  Name used to reference this scene (e.g., "menu", "gameplay").
         * @param scene Shared pointer to the scene instance.
         */
        void registerScene(const std::string& name, std::shared_ptr<Scene> scene);

        /**
         * @brief Retrieve a previously registered scene by name.
         *
         * @param name Scene identifier.
         * @return Shared pointer to the scene, or nullptr if not found.
         */
        std::shared_ptr<Scene> getScene(const std::string& name) const;

        /**
         * @brief Switch to a named scene, handling shutdown/start transitions.
         *
         * Steps:
         *  1. Shutdown the current scene (if one exists).
         *  2. Look up the new scene by name.
         *  3. Call its `start()` method.
         *  4. Mark it as the active scene.
         *
         * @param name Scene identifier to switch to.
         * @return The newly activated scene, or nullptr if not found.
         */
        std::shared_ptr<Scene> changeScene(const std::string& name);

        /**
         * @brief Get the currently active scene.
         *
         * @return Shared pointer to the active scene, or nullptr if none active.
         */
        std::shared_ptr<Scene> getCurrentScene() const;

    private:
        std::unordered_map<std::string, std::shared_ptr<Scene>> m_scenes; ///< Registered scenes.
        std::shared_ptr<Scene> m_currentScene = nullptr;                   ///< Current active scene.
    };

} // namespace retronomicon::scene
