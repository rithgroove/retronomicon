#pragma once

#include <SDL.h>
#include <string>
#include "retronomicon/lib/core/scene.h"

namespace retronomicon::platformer::scene {

    class SplashScene : public retronomicon::lib::core::Scene {
    public:
        explicit SplashScene(SDL_Renderer* renderer);
        ~SplashScene() override;

        void init() override;
        void update(float dt) override;
        void render() override;
        void shutdown() override;

        bool isFinished() const;

    private:
        SDL_Renderer* m_renderer;
        SDL_Texture* m_logoTexture = nullptr;

        float m_timer = 0.0f;
        float m_duration = 3.0f;
        bool m_finished = false;

        void loadAssets();
        void unloadAssets();
        void handleInput();
    };

} // namespace retronomicon::platformer::scene
