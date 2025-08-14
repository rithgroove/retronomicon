#pragma once

#include <memory>
#include <SDL.h>
#include "retronomicon/lib/core/scene.h"
#include "retronomicon/lib/scene/scene_manager.h"
#include "retronomicon/lib/graphic/window.h"
#include "retronomicon/lib/input/input_state.h"
/**
 * @brief The namespace for the core features of retronomicon
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
             */
            void setScene(std::shared_ptr<Scene> newScene) {
                m_activeScene = std::move(newScene);
            }


            void registerScene(const std::string &name , std::shared_ptr<Scene> newScene) {
                m_sceneManager.registerScene(name,newScene);
            }

            /***************************** Getter *****************************/
            SDL_Renderer* getRenderer(){
                return m_window->getRenderer();
            }

            /***************************** Main Methods *****************************/
            /**
             * @brief changes scene using scene manager (with reset/initialization logic)
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
            
            InputState* getInputState(){return m_inputState;}       

        private:


            /***************************** Attribute *****************************/
            InputState* m_inputState = nullptr;
            retronomicon::lib::graphic::Window * m_window = nullptr; 
            bool m_running = false; 
            std::shared_ptr<Scene> m_activeScene;
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