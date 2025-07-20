#include "retronomicon/lib/graphic/window.h"
#include <stdexcept>
/**
 * @brief The namespace for graphic classes
 */
namespace retronomicon::lib::graphic{

    /***************************** Constructor *****************************/
    /**
     * @brief the constructor for our windows
     * 
     * @param title the name of the window
     * @param width the width of the window
     * @param height the height of the window
     * @param fullscreen  boolean representing fullscreen
     */
    Window::Window(const std::string& title, int width, int height, bool fullscreen)
        : m_width(width), m_height(height), m_fullscreen(fullscreen) {
        initialize(title, width, height, fullscreen);
    }

    /***************************** Destructor *****************************/
    /**
     * @brief the destructor for the windows
     */
    Window::~Window() {
        cleanup();
    }

    /***************************** Main Method *****************************/

    /**
     * @brief a method to clear the screen
     */
    void Window::clear() {
        SDL_SetRenderDrawColor(m_renderer, m_clearColor.r, m_clearColor.g, m_clearColor.b, m_clearColor.a);
        SDL_RenderClear(m_renderer);
    }

    /**
     * @brief a method to present all rendered image
     */
    void Window::present() {
        SDL_RenderPresent(m_renderer);
    }

    /**
     * @brief a method to toggle full screen (not tested)
     */
    void Window::toggleFullscreen() {
        m_fullscreen = !m_fullscreen;
        SDL_SetWindowFullscreen(m_window, m_fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    }

    /**
     * @brief a method to handle screen resize (not tested)
     */
    void Window::handleResize(int newWidth, int newHeight) {
        m_width = newWidth;
        m_height = newHeight;
        // Optional: adjust render scale or UI here
    }

    /***************************** Private Main Method *****************************/
    /**
     * @brief the method to initialize SDL, SDL_Window, and SDL_Renderer
     * 
     * @param title the name of the window
     * @param width the width of the window
     * @param height the height of the window
     * @param fullscreen  boolean representing fullscreen
     */
    void Window::initialize(const std::string& title, int width, int height, bool fullscreen) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) { 
            throw std::runtime_error("[Window.initialize] Failed to initialize SDL_INIT_VIDEO");
        }

        Uint32 windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
        if (fullscreen) {
            windowFlags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
        }

        m_window = SDL_CreateWindow(title.c_str(),
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    width, height, SDL_WINDOW_FOREIGN);
        if (!m_window) {
            throw std::runtime_error("[Window.initialize] Failed to create SDL_WINDOW");
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!m_renderer) {
            throw std::runtime_error("[Window.initialize] Failed to create SDL_RENDERER");
        }
    }

    /**
     * @brief the method to destroy sdl objects. called by destructor
     */
    void Window::cleanup() {
        if (m_renderer) {
            SDL_DestroyRenderer(m_renderer);
            m_renderer = nullptr;
        }

        if (m_window) {
            SDL_DestroyWindow(m_window);
            m_window = nullptr;
        }

        SDL_Quit();
    }
}