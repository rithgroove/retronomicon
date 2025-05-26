#include "retronomicon/lib/graphic/window.h"
#include <iostream>

namespace retronomicon {
    namespace lib{
        namespace graphic{

            Window::Window(const std::string& title, int width, int height, bool fullscreen)
                : m_width(width), m_height(height), m_fullscreen(fullscreen) {
                initialize(title, width, height, fullscreen);
            }

            Window::~Window() {
                cleanup();
            }

            void Window::initialize(const std::string& title, int width, int height, bool fullscreen) {
                if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                    std::cerr << "SDL could not initialize: " << SDL_GetError() << std::endl;
                    return;
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
                    std::cerr << "Window could not be created: " << SDL_GetError() << std::endl;
                    return;
                }

                m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
                if (!m_renderer) {
                    std::cerr << "Renderer could not be created: " << SDL_GetError() << std::endl;
                    return;
                }
            }

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

            void Window::clear() {
                SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255); // Black background
                SDL_RenderClear(m_renderer);
            }

            void Window::present() {
                SDL_RenderPresent(m_renderer);
            }

            void Window::toggleFullscreen() {
                m_fullscreen = !m_fullscreen;
                SDL_SetWindowFullscreen(m_window, m_fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
            }

            void Window::handleResize(int newWidth, int newHeight) {
                m_width = newWidth;
                m_height = newHeight;
                // Optional: adjust render scale or UI here
            }

            int Window::getWidth() const {
                return m_width;
            }

            int Window::getHeight() const {
                return m_height;
            }

            SDL_Renderer* Window::getRenderer() const {
                return m_renderer;
            }

            SDL_Window* Window::getRawWindow() const {
                return m_window;
            }

        }
    }
}