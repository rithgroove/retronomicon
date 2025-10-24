#include "retronomicon/engine/game_engine.h"

#include <iostream>
#include <stdexcept>
#include <chrono>
#include <thread>

namespace retronomicon::engine {
    using retronomicon::graphics::IWindow;
    /***************************** Constructor *****************************/
    
    /**
     * @brief default constructor
     */
    GameEngine::GameEngine(std::shared_ptr<RenderManager> renderManager, std::shared_ptr<SceneManager> sceneManager):m_renderManager(renderManager),m_sceneManager(sceneManager){
    }

    /***************************** Destructor *****************************/
    
    // GameEngine::~GameEngine() = default;

    /***************************** Main Methods *****************************/
    
    /**
     * @brief changes scene using scene manager (with reset/initialization logic)
     *
     * @param name the scene name to switch to
     */
    void GameEngine::changeScene(const std::string& name) {
        auto nextScene = m_sceneManager->changeScene(name);
        if (nextScene) {
            // m_activeScene.reset();
            setScene(nextScene);
        } else {
            m_running =false;
            // Log or handle error: unknown scene name
            // SDL_Log("Failed to change scene: %s", name.c_str());
        }
    }

    /**
     * @brief method to init all necessary components
     * @params title title of the game
     * @params width the window width 
     * @params height the window height
     */
    bool GameEngine::init(const char* title, int width, int height) {
        try{
            // m_inputState = std::make_shared<InputState>();
            // m_window = std::make_unique<Window>(title, width, height);
            // m_running = true;
        }catch (const std::runtime_error &e){
            std::cerr << "Failure to init game engine: " << e.what() << std::endl;
            return false;
        }catch (...) { 
            // Catch-all handler for any other exception type
            std::cerr << "Caught an unknown exception during game engine initialization." << std::endl;
            return false;
        }
        return true;
    }


    /**
     * @brief method to start mainloop
     */

    void GameEngine::run() {
        using clock = std::chrono::steady_clock;
        using namespace std::chrono_literals;

        const double targetDelta = 1.0 / 60.0; // 60 FPS target
        auto lastTime = clock::now();

        m_running = true;

        while (m_running) {
            auto currentTime = clock::now();
            std::chrono::duration<double> elapsed = currentTime - lastTime;
            double deltaTime = elapsed.count();
            lastTime = currentTime;

            // --- Engine core loop ---
            handleEvents();
            update(static_cast<float>(deltaTime));
            render();
            // ------------------------

            // Frame limiting (avoid CPU spin)
            auto frameDuration = clock::now() - currentTime;
            double frameTime = frameDuration.count();
            if (frameTime < targetDelta) {
                auto sleepDuration = std::chrono::duration<double>(targetDelta - frameTime);
                std::this_thread::sleep_for(std::chrono::duration_cast<std::chrono::milliseconds>(sleepDuration));
            }
        }
    }

    /***************************** Main Private Methods *****************************/
    /**
     * @brief method to pool event before updating
     */
    void GameEngine::handleEvents() {
        // SDL_Event event;
        // while (SDL_PollEvent(&event)) {
        //     if (event.type == SDL_QUIT)
        //         m_running = false;

        //     // if (m_activeScene)
        //     //     m_activeScene->handleInput(event);
        // }
    }

    /**
     * @brief method to pool event before updating
     * 
     * @param dt, the delta time since last update
     */
    void GameEngine::update(float dt) {
        //renderer->clear();
        // m_inputState->updateFromSDL();
        if (m_activeScene)
            m_activeScene->update(dt);
        //renderer->show();
    }

    /**
     * @brief the render method
     */
    void GameEngine::render() {
        // // clear
        // m_window->clear();
        m_renderManager->clear();
        if (m_activeScene)
            m_renderManager->render(m_activeScene);
        m_renderManager->show();

        // m_window->present();
    }


} // namespace retronomicon::core