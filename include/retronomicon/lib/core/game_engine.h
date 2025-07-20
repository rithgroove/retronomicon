#pragma once

#include <memory>
#include <SDL2/SDL.h>
#include "retronomicon/lib/core/scene.h"

/**
 * @brief The namespace for the core features of retronomicon
 */
namespace retronomicon::lib::core {
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
             * @brief default destructor
             */
            ~GameEngine();

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

            /**
             * @brief method to start mainloop
             */
            void shutdown();


            /**
             * @brief set active scene
             */
            void setScene(std::shared_ptr<Scene> newScene);

        private:
            SDL_Window* m_window = nullptr;
            SDL_Renderer* m_renderer = nullptr;
            bool m_running = false;

            std::shared_ptr<Scene> m_activeScene;

            void handleEvents();
            void update(float dt);
            void render();
    };

} // namespace retronomicon::lib::core