#pragma once

#include <memory>
#include <SDL.h>
#include "retronomicon/lib/core/scene.h"
#include "retronomicon/lib/graphic/window.h"

/**
 * @brief The namespace for the core features of retronomicon
 */
namespace retronomicon::lib::engine {
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

            /***************************** Main Methods *****************************/

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

        private:


            /***************************** Attribute *****************************/
            retronomicon::lib::graphic::Window * m_window = nullptr; 
            bool m_running = false; 
            std::shared_ptr<Scene> m_activeScene;

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