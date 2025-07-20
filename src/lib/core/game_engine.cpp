#include "retronomicon/lib/core/game_engine.h"
#include <iostream>

namespace retronomicon::lib::core {

GameEngine::GameEngine() = default;

GameEngine::~GameEngine() {
    shutdown();
}

bool GameEngine::init(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Failed: " << SDL_GetError() << '\n';
        return false;
    }

    m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (!m_window) {
        std::cerr << "SDL_CreateWindow Failed: " << SDL_GetError() << '\n';
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (!m_renderer) {
        std::cerr << "SDL_CreateRenderer Failed: " << SDL_GetError() << '\n';
        return false;
    }

    m_running = true;
    return true;
}

void GameEngine::run() {
    const float targetDelta = 1.0f / 60.0f;
    Uint32 lastTime = SDL_GetTicks();

    while (m_running) {
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        handleEvents();
        update(deltaTime);
        render();

        SDL_Delay(1); // slight delay to prevent CPU spin
    }
}

void GameEngine::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            m_running = false;

        if (m_activeScene)
            m_activeScene->handleInput(event);
    }
}

void GameEngine::update(float dt) {
    if (m_activeScene)
        m_activeScene->update(dt);
}

void GameEngine::render() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    if (m_activeScene)
        m_activeScene->render(m_renderer);

    SDL_RenderPresent(m_renderer);
}

void GameEngine::shutdown() {
    if (m_renderer) SDL_DestroyRenderer(m_renderer);
    if (m_window) SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void GameEngine::setScene(std::shared_ptr<Scene> newScene) {
    m_activeScene = std::move(newScene);
}

} // namespace retronomicon::lib::core