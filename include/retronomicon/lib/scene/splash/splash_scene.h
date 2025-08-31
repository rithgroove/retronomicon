#pragma once

#include <SDL.h>
#include <memory>
#include <string>
#include <functional>
#include "retronomicon/lib/engine/game_engine.h"
#include "retronomicon/lib/core/scene.h"
#include "retronomicon/lib/asset/image_asset.h"
#include "retronomicon/lib/asset/asset_manager.h"

namespace retronomicon::lib::scene::splash {
    using retronomicon::lib::asset::ImageAsset;
    using retronomicon::lib::asset::AssetManager;
    using retronomicon::lib::engine::GameEngine;
    class SplashScene : public retronomicon::lib::core::Scene {
    public:
        explicit SplashScene(GameEngine *engine,std::string filePath,std::string fileKey, const std::string nextScene);
        ~SplashScene() override;

        void init() override;

        // void deinit() override;

        void shutdown() override;

        void setImage(SDL_Texture* texture){ m_logoTexture = texture;}

    private:
        std::string m_filePath;
        std::string m_fileKey;
        std::shared_ptr<AssetManager> m_assetManager;
        std::shared_ptr<ImageAsset> m_image = nullptr;
        GameEngine* m_engine = nullptr;
        SDL_Renderer* m_renderer = nullptr;
        SDL_Texture* m_logoTexture = nullptr;
        std::string m_nextScene = nullptr; // the default is Menu, but you can adjust it

        float m_duration = 3.0f;
        
        InputMap* generateInputMap();
        void setupSystem();
        void setupLogo();
    };

} // namespace retronomicon::platformer::scene
