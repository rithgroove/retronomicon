#pragma once

#include <memory>
#include <SDL2/SDL.h>
#include "retronomicon/lib/core/scene.h"

namespace retronomicon::lib::core {

class GameEngine {
public:
    GameEngine();
    ~GameEngine();

    bool init(const char* title, int width, int height);
    void run();
    void shutdown();

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