#pragma once

#include <memory>
#include <SDL.h>
#include "retronomicon/lib/core/scene.h"
#include "retronomicon/lib/scene/scene_manager.h"
#include "retronomicon/lib/graphic/window.h"
#include "retronomicon/lib/input/input_state.h"
/**
 * @brief The namespace for the core engine features of retronomicon
 */
namespace retronomicon::lib::engine {
    using retronomicon::lib::input::InputState;
    /**
     * @brief Game Engine class (the main class that you need to run)
     */
    class GameEngine {
        public:

            /***************************** Constructor *****************************/

            /**
             * @brief default constructor
             * initiate m_inputState 
             */
            GameEngine();

            /***************************** Destructor *****************************/

            /**
             * @brief destructor (calls shutdown when killed)
             */
            // ~GameEngine();

            /***************************** Setter *****************************/

            /**
             * @brief set active scene
             * 
             * @param newScene the shared pointer of the new scene we wanted to set
             */
            void setScene(std::shared_ptr<Scene> newScene) noexcept {
                m_activeScene = std::move(newScene);
            }

            /**
             * @brief register scene in m_sceneManager. so we could use scene manager to change scene by keyword
             * 
             * @param name the name of this scene
             * @param newScene the shared pointer of the new scene we wanted to register
             */
            void registerScene(const std::string &name , std::shared_ptr<Scene> newScene) noexcept{
                m_sceneManager.registerScene(name,newScene);
            }

            /**
             * @brief method to get InputState
             * 
             * @return inputState
             */
            std::shared_ptr<InputState>  getInputState() noexcept {return m_inputState;}  


            /***************************** Getter *****************************/

            /**
             * @brief inline method to get the renderer
             * 
             * @return the SDL_Renderer from window
             */
            [[nodiscard]] SDL_Renderer* getRenderer() noexcept{
                return m_window->getRenderer();
            }

            /***************************** Main Methods *****************************/

            /**
             * @brief changes scene using scene manager (with reset/initialization logic)
             * 
             * @param name the scene name to switch to
             */
            void changeScene(const std::string& name);

            /**
             * @brief method to init all necessary components
             * @params title title of the game
             * @params width the window width 
             * @params height the window height
             */
            bool init(const char* title, int width, int height);

            /**
             * @brief method to start mainloop
             */
            void run();
                 
            /**
             * @brief method to set m_running to false which will trigger the engine to exit mainloop.
             */
            void stop() noexcept {m_running = false;}

        private:
            /***************************** Attribute *****************************/

            std::shared_ptr<InputState> m_inputState;
            std::unique_ptr<retronomicon::lib::graphic::Window> m_window;
            std::shared_ptr<Scene> m_activeScene;

            bool m_running = false; 
            retronomicon::lib::scene::SceneManager m_sceneManager;

            /***************************** Main Private Methods *****************************/

            /**
             * @brief method to pool event before updating
             */
            void handleEvents();


            /**
             * @brief method to pool event before updating
             * 
             * @param dt, the delta time since last update
             */
            void update(float dt);

            /**
             * @brief the render method
             */
            void render();
    };

} // namespace retronomicon::lib::core