#pragma once

#include <SDL.h>
#include <string>
#include <iostream>

/**
 * @brief The namespace for graphic classes
 */
namespace retronomicon::lib::graphic{
    /**
     * @brief The class representing a single window
     */
    class Window {
        public:
            /**
             * @brief the constructor for our windows
             * 
             * @param title the name of the window
             * @param width the width of the window
             * @param height the height of the window
             * @param fullscreen  boolean representing fullscreen
             */
            Window(const std::string& title, int width, int height, bool fullscreen = false);

            /**
             * @brief the destructor for the windows
             */
            ~Window();


            void clear();
            void present();
            void toggleFullscreen();
            void handleResize(int newWidth, int newHeight);

            /**
             * @brief the method to get the window width
             * 
             * @return the window width
             */
            int getWidth() const;

            /**
             * @brief the method to get the window height
             * 
             * @return the window height
             */
            int getHeight() const;

            /**
             * @brief the method to get the renderer
             * 
             * @return the SDL_Renderer
             */
            SDL_Renderer* getRenderer() const;

            /**
             * @brief the method to get the SDL_Window
             * 
             * @return the SDL_Window
             */
            SDL_Window* getRawWindow() const;

        private:
            void initialize(const std::string& title, int width, int height, bool fullscreen);
            void cleanup();

            SDL_Window* m_window = nullptr;
            SDL_Renderer* m_renderer = nullptr;
            int m_width = 0;
            int m_height = 0;
            bool m_fullscreen = false;
    };
}
