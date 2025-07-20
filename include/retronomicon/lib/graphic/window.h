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

            /***************************** Constructor *****************************/
            /**
             * @brief the constructor for our windows
             * 
             * @param title the name of the window
             * @param width the width of the window
             * @param height the height of the window
             * @param fullscreen  boolean representing fullscreen
             */
            Window(const std::string& title, int width, int height, bool fullscreen = false);

            /***************************** Destructor *****************************/
            /**
             * @brief the destructor for the windows
             */
            ~Window();

            /***************************** Setter *****************************/

            /**
             * @brief the window background color. 
             * when we wanted to clear the screen this will be the base color of the window
             * 
             * @param color the color we wanted
             */
            void setClearColor(const SDL_Color& color) { m_clearColor = color; }

            /***************************** Getter *****************************/
            
            /**
             * @brief the method to get the window width
             * 
             * @return the window width
             */
            int getWidth() const{return m_width;}

            /**
             * @brief the method to get the window height
             * 
             * @return the window height
             */
            int getHeight() const{return m_height;}

            /**
             * @brief the method to get the renderer
             * 
             * @return the SDL_Renderer
             */
            SDL_Renderer* getRenderer() const{return m_renderer;}

            /**
             * @brief the method to get the SDL_Window
             * 
             * @return the SDL_Window
             */
            SDL_Window* getRawWindow() const{return m_window;}

            /***************************** Utility *****************************/

            /**
             * @brief get the full screen status
             * 
             * @return true if in fullscreen mode, false otherwise
             */
            boolean isFullScreen() const{return m_fullscreen;}

            /***************************** Main Method *****************************/

            /**
             * @brief a method to clear the screen
             */
            void clear();

            /**
             * @brief a method to present all rendered image
             */
            void present();

            /**
             * @brief a method to toggle full screen (not tested)
             */
            void toggleFullscreen();

            /**
             * @brief a method to handle screen resize (not tested)
             */
            void handleResize(int newWidth, int newHeight);

        private:
            /***************************** Attributes *****************************/
            SDL_Window* m_window = nullptr;
            SDL_Renderer* m_renderer = nullptr;
            int m_width = 0;
            int m_height = 0;
            bool m_fullscreen = false;
            SDL_Color m_clearColor { 0, 0, 0, 255 }; 

            /***************************** Private Main Method *****************************/
            /**
             * @brief the method to initialize SDL, SDL_Window, and SDL_Renderer
             * 
             * @param title the name of the window
             * @param width the width of the window
             * @param height the height of the window
             * @param fullscreen  boolean representing fullscreen
             */
            void initialize(const std::string& title, int width, int height, bool fullscreen);

            /**
             * @brief the method to destroy sdl objects. called by destructor
             */
            void cleanup();

    };
}
