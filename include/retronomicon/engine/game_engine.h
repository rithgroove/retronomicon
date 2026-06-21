#pragma once

#include <memory>

#include "retronomicon/scene/scene.h"
#include "retronomicon/scene/scene_manager.h"
#include "retronomicon/graphics/i_window.h"
#include "retronomicon/input/input_state.h"
#include "retronomicon/input/input_map.h"
#include "retronomicon/input/raw_input.h"
#include "retronomicon/manager/render_manager.h"
#include "retronomicon/graphics/renderer/i_renderer.h"
#include "retronomicon/audio/i_audio_player.h"

/**
 * @brief Core runtime namespace for the Retronomicon engine.
 */
namespace retronomicon::engine {

    using retronomicon::input::InputState;
    using retronomicon::input::InputMap;
    using retronomicon::input::RawInput;
    using retronomicon::scene::Scene;
    using retronomicon::scene::SceneManager;
    using retronomicon::manager::RenderManager;
    using retronomicon::graphics::renderer::IRenderer;
    using retronomicon::audio::IAudioPlayer;

    /**
     * @brief The main engine class that coordinates rendering, scenes, input, and the game loop.
     *
     * GameEngine owns or references the major subsystems:
     *  - Window and renderer (via RenderManager)
     *  - Scene management (SceneManager)
     *  - Input system (InputState, InputMap, RawInput)
     *  - Audio playback (IAudioPlayer)
     *
     * Typical usage:
     * @code
     * auto engine = std::make_shared<GameEngine>(renderManager, sceneManager);
     * engine->setInputModule(inputMap, rawInput);
     * engine->init("My Game", 1280, 720);
     * engine->registerScene("menu", std::make_shared<MenuScene>());
     * engine->changeScene("menu");
     * engine->run();
     * @endcode
     *
     * Lifecycle overview:
     *  1. Construct engine with render + scene managers.
     *  2. Register scenes or set an initial active scene.
     *  3. Call init() to create window and initialize subsystems.
     *  4. Call run() to enter the main loop (events → update → render).
     *  5. Call stop() to break out of the loop and shut down.
     */
    class GameEngine {
    public:

        /***************************** Constructor *****************************/

        /**
         * @brief Construct the engine with rendering + scene systems preconfigured.
         *
         * Initializes the InputState object internally.
         *
         * @param renderManager Responsible for creating the renderer and managing frame rendering.
         * @param sceneManager  Manages scene registration, loading, and transitions.
         */
        GameEngine(std::shared_ptr<RenderManager> renderManager,
                   std::shared_ptr<SceneManager> sceneManager);

        /***************************** Scene Management *****************************/

        /**
         * @brief Immediately set the active scene (bypasses SceneManager logic).
         *
         * Used sparingly — normally `changeScene()` is preferred.
         *
         * @param newScene Scene instance to activate.
         */
        void setScene(std::shared_ptr<Scene> newScene) noexcept {
            m_activeScene = std::move(newScene);
        }

        /**
         * @brief Register a scene into the SceneManager so it can be accessed by name.
         *
         * @param name     Human-readable identifier for the scene.
         * @param newScene Scene instance to associate with that name.
         */
        void registerScene(const std::string &name, std::shared_ptr<Scene> newScene) noexcept {
            m_sceneManager->registerScene(name, newScene);
        }

        /**
         * @brief Request a change to a named scene.
         *
         * This handles initialization, reset logic, and returning the
         * correct instance from SceneManager.
         *
         * @param name Name of the scene to switch to.
         */
        void changeScene(const std::string& name);

        /***************************** Input System *****************************/

        /**
         * @brief Attach input modules to the engine.
         *
         * @param inputMap  Defines logical input bindings (e.g., jump, move).
         * @param rawInput  Supplies raw hardware input data.
         */
        void setInputModule(std::shared_ptr<InputMap> inputMap,
                            std::shared_ptr<RawInput> rawInput) {
            m_inputMap = inputMap;
            m_rawInput = rawInput;
            m_inputState->setInputMap(inputMap);
            m_inputState->setRawInput(rawInput);
        }

        /**
         * @brief Assign the audio playback backend.
         *
         * @param audioPlayer Audio system implementation.
         */
        void setAudioPlayer(std::shared_ptr<IAudioPlayer> audioPlayer) {
            m_audioPlayer = audioPlayer;
        }

        /***************************** Getters *****************************/

        /// @return The current InputState (merged logical + raw input).
        std::shared_ptr<InputState> getInputState() noexcept { return m_inputState; }

        /// @return The current InputMap.
        std::shared_ptr<InputMap> getInputMap() noexcept { return m_inputMap; }

        /// @return The raw input provider (keyboard, controller, touchscreen, etc.).
        std::shared_ptr<RawInput> getRawInput() noexcept { return m_rawInput; }

        /// @return The active renderer provided by the RenderManager.
        std::shared_ptr<IRenderer> getRenderer() { return m_renderManager->getRenderer(); }

        /// @return The scene currently active in the SceneManager.
        std::shared_ptr<Scene> getCurrentScene() { return m_sceneManager->getCurrentScene(); }

        /// @return The active audio backend.
        std::shared_ptr<IAudioPlayer> getAudioPlayer() { return m_audioPlayer; }

        /***************************** Initialization *****************************/

        /**
         * @brief Validate that required injected subsystems are present.
         *
         * Core does not create concrete windows, renderers, input providers, or
         * audio devices. Backend modules own that setup and inject the results
         * before the engine loop starts.
         *
         * @param title  Window title string.
         * @param width  Window width in pixels.
         * @param height Window height in pixels.
         *
         * @return True if required core subsystems are available.
         */
        bool init(const char* title, int width, int height);

        /***************************** Main Loop *****************************/

        /**
         * @brief Begin the engine's main loop.
         *
         * Loop sequence:
         *  - Poll + process input events (`handleEvents()`)
         *  - Compute dt and call `update(dt)`
         *  - Render the current scene (`render()`)
         */
        void run();

        /**
         * @brief Advance one engine frame.
         *
         * This is the testable form of the main loop body. Runtime code should
         * normally call run(); tests and tooling can call tick() to verify input,
         * scene update, and render coordination without opening a platform window
         * or entering an infinite loop.
         *
         * @param dt Delta time to pass to the active scene.
         */
        void tick(float dt);

        /**
         * @brief Stop the main loop on next iteration.
         */
        void stop() noexcept { m_running = false; }

    private:

        /***************************** Subsystems *****************************/
        std::shared_ptr<RenderManager> m_renderManager;  ///< Responsible for renderer creation + frame orchestration.
        std::shared_ptr<SceneManager>  m_sceneManager;   ///< Handles scene instances and transitions.
        std::shared_ptr<InputState>    m_inputState;     ///< Unified input state object.
        std::unique_ptr<retronomicon::graphics::IWindow> m_window; ///< Game window implementation.

        std::shared_ptr<Scene>         m_activeScene;    ///< Direct active scene pointer (may mirror SceneManager).
        std::shared_ptr<InputMap>      m_inputMap;       ///< Logical input mapping.
        std::shared_ptr<RawInput>      m_rawInput;       ///< Raw device input.
        std::shared_ptr<IAudioPlayer>  m_audioPlayer;    ///< Audio backend.

        bool m_running = false; ///< Controls main loop execution.

        /***************************** Internal Loop Helpers *****************************/

        /**
         * @brief Poll and process pending input events.
         */
        void handleEvents();

        /**
         * @brief Update the active scene.
         *
         * @param dt Delta time since previous frame (in seconds).
         */
        void update(float dt);

        /**
         * @brief Render the current frame.
         *
         * Delegates to the RenderManager → Renderer → Scene rendering.
         */
        void render();
    };

} // namespace retronomicon::engine
