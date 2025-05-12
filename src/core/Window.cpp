#include "MyGame/core/Window.h"
#include <iostream>

namespace MyGame {

Window::Window(const std::string& title, int width, int height, bool fullscreen)
    : m_width(width), m_height(height), m_isFullscreen(fullscreen) {
    initSDL(title, width, height, fullscreen);
}

Window::~Window() {
    cleanup();
}

void Window::initSDL(const std::string& title, int width, int height, bool fullscreen) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }

    Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    if (fullscreen) {
        flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    }

    m_window = SDL_CreateWindow(title.c_str(),
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                width, height, flags);
    if (!m_window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1,
                                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!m_renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return;
    }
}

void Window::cleanup() {
    if (m_renderer) SDL_DestroyRenderer(m_renderer);
    if (m_window) SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Window::clear() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255); // default black
    SDL_RenderClear(m_renderer);
}

void Window::present() {
    SDL_RenderPresent(m_renderer);
}

void Window::toggleFullscreen() {
    m_isFullscreen = !m_isFullscreen;
    Uint32 flags = m_isFullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;
    SDL_SetWindowFullscreen(m_window, flags);
}

void Window::handleResize(int newWidth, int newHeight) {
    m_width = newWidth;
    m_height = newHeight;
    // Resize your render targets if needed here
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

} // namespace MyGame
