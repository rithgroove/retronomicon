#include "retronomicon/lib/graphic/window.h"
#include <stdexcept>
/**
 * @brief The namespace for graphic classes
 */
namespace retronomicon::lib::graphic{
    int retronomicon::lib::graphic::Window::m_width = 0;
    int retronomicon::lib::graphic::Window::m_height = 0;
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
        : m_fullscreen(fullscreen) {
        this->setSize(width,height);
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
        glClearColor(
            m_clearColor.r / 255.0f,
            m_clearColor.g / 255.0f,
            m_clearColor.b / 255.0f,
            m_clearColor.a / 255.0f
        );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    /**
     * @brief a method to present all rendered image
     */
    void Window::present() {
        SDL_GL_SwapWindow(m_window);
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

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"); // linear

        Uint32 windowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
        if (fullscreen) {
            windowFlags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        m_window = SDL_CreateWindow(title.c_str(),
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    width, height, windowFlags);
        if (!m_window) {
            throw std::runtime_error("[Window.initialize] Failed to create SDL_WINDOW");
        }

        m_glContext = SDL_GL_CreateContext(m_window);
        if (!m_glContext) {
            throw std::runtime_error("[Window.initialize] Failed to create SDL_GLContext");
        }
        SDL_GL_SetSwapInterval(1); // enable vsync
    }

    /**
     * @brief the method to destroy sdl objects. called by destructor
     */
    void Window::cleanup() {
        if (m_glContext) {
            SDL_GL_DeleteContext(m_glContext);
            m_glContext = nullptr;
        }

        if (m_window) {
            SDL_DestroyWindow(m_window);
            m_window = nullptr;
        }

        SDL_Quit();
    }
}