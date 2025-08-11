#pragma once

#include <SDL.h>
#include <memory>
#include <string>
#include <functional>
#include "retronomicon/lib/engine/game_engine.h"
#include "retronomicon/lib/core/scene.h"
#include "retronomicon/lib/asset/image_asset.h"

namespace retronomicon::lib::scene::splash {
    using retronomicon::lib::asset::ImageAsset;
    using retronomicon::lib::engine::GameEngine;
    class SplashScene : public retronomicon::lib::core::Scene {
    public:
        explicit SplashScene(GameEngine *engine,std::shared_ptr<ImageAsset> image);
        ~SplashScene() override;

        void init() override;
        // void update(float dt) override;
        // void render() override;
        void shutdown() override;

        bool isFinished() const;

        // New: Set the callback to change scene
        void setOnFinish(std::function<void(const std::string&)> callback);

        void setImage(SDL_Texture* texture);

    private:
        std::shared_ptr<ImageAsset> m_image = nullptr;
        GameEngine* m_engine = nullptr;
        SDL_Renderer* m_renderer = nullptr;
        SDL_Texture* m_logoTexture = nullptr;

        float m_timer = 0.0f;
        float m_duration = 3.0f;
        bool m_finished = false;

        std::function<void(const std::string&)> m_onFinish;

        void loadAssets();
        void unloadAssets();
        void handleInput();
    };

} // namespace retronomicon::platformer::scene
