#include "retronomicon/lib/engine/game_engine.h"
#include <iostream>
#include <stdexcept>

namespace retronomicon::lib::engine {
    using retronomicon::lib::graphic::Window;
    /***************************** Constructor *****************************/
    
    /**
     * @brief default constructor
     */
    GameEngine::GameEngine() = default;

    /***************************** Destructor *****************************/
    
    // GameEngine::~GameEngine() = default;

    /***************************** Main Methods *****************************/
    
    /**
     * @brief changes scene using scene manager (with reset/initialization logic)
     * @param name the scene name to switch to
     */
    void GameEngine::changeScene(const std::string& name) {
        auto nextScene = m_sceneManager.changeScene(name);
        std::cout<<"masuk engine Change scene"<<std::endl;
        if (nextScene) {
            setScene(nextScene);
        } else {
            // Log or handle error: unknown scene name
            SDL_Log("Failed to change scene: %s", name.c_str());
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
            m_window = new Window(title,width,height);
            m_running = true;
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

        // const float targetDelta = 1.0f / 60.0f; //should be used as target, but the code doesn't use it at all.
        Uint32 lastTime = SDL_GetTicks();

        while (m_running) {
            Uint32 currentTime = SDL_GetTicks();
            float deltaTime = (currentTime - lastTime) / 1000.0f;
            lastTime = currentTime;

            handleEvents();
            update(deltaTime);
            render();

            SDL_Delay(1); // slight delay to prevent CPU spin
        }
    }

    /***************************** Main Private Methods *****************************/
    /**
     * @brief method to pool event before updating
     */
    void GameEngine::handleEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                m_running = false;

            // if (m_activeScene)
            //     m_activeScene->handleInput(event);
        }
    }

    /**
     * @brief method to pool event before updating
     * 
     * @param dt, the delta time since last update
     */
    void GameEngine::update(float dt) {
        if (m_activeScene)
            m_activeScene->update(dt);
    }

    /**
     * @brief the render method
     */
    void GameEngine::render() {
        // clear
        m_window->clear();

        if (m_activeScene)
            m_activeScene->render();

        m_window->present();
    }


} // namespace retronomicon::lib::core