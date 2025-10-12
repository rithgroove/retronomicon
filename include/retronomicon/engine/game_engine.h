#pragma once

#include <memory>
#include "retronomicon/scene/scene.h"
#include "retronomicon/scene/scene_manager.h"
#include "retronomicon/graphics/i_window.h"
#include "retronomicon/input/input_state.h"
/**
 * @brief The namespace for the core engine features of retronomicon
 */
namespace retronomicon::engine {
    using retronomicon::input::InputState;
    using retronomicon::scene::Scene;
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


            /***************************** Getter *****************************/

            /**
             * @brief method to get InputState
             * 
             * @return inputState
             */
            std::shared_ptr<InputState>  getInputState() noexcept {return m_inputState;}    


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
            std::unique_ptr<retronomicon::graphics::IWindow> m_window;
            std::shared_ptr<Scene> m_activeScene;

            bool m_running = false; 
            retronomicon::scene::SceneManager m_sceneManager;

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

} // namespace retronomicon::core