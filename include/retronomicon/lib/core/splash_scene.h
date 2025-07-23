#pragma once

#include <SDL.h>
#include <string>
#include <functional>
#include "retronomicon/lib/core/scene.h"

namespace retronomicon::lib::core {

    class SplashScene : public retronomicon::lib::core::Scene {
    public:
        explicit SplashScene(SDL_Renderer* renderer);
        ~SplashScene() override;

        void init() override;
        void update(float dt) override;
        void render() override;
        void shutdown() override;

        bool isFinished() const;

        // New: Set the callback to change scene
        void setOnFinish(std::function<void(const std::string&)> callback);

    private:
        SDL_Renderer* m_renderer;
        SDL_Texture* m_logoTexture = nullptr;

        float m_timer = 0.0f;
        float m_duration = 10.0f;
        bool m_finished = false;

        std::function<void(const std::string&)> m_onFinish;

        void loadAssets();
        void unloadAssets();
        void handleInput();
    };

} // namespace retronomicon::platformer::scene
