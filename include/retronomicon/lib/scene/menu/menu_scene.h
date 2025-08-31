#pragma once
#include <memory>
#include <vector>
#include "retronomicon/lib/core/scene.h"
#include "retronomicon/lib/asset/asset_manager.h"
#include "retronomicon/lib/asset/image_asset.h"
#include "retronomicon/lib/asset/font_asset.h"
#include "retronomicon/lib/asset/music_asset.h"
#include "retronomicon/lib/asset/sound_effect_asset.h"
#include "retronomicon/lib/engine/game_engine.h"
namespace retronomicon::lib::scene::menu{
    using retronomicon::lib::asset::AssetManager;
    using retronomicon::lib::asset::ImageAsset;
    using retronomicon::lib::asset::FontAsset;
    using retronomicon::lib::asset::MusicAsset;
    using retronomicon::lib::asset::SoundEffectAsset;
    using retronomicon::lib::engine::GameEngine;
    class MenuScene : public retronomicon::lib::core::Scene {
    public:
        MenuScene();
        MenuScene(
            GameEngine* engine, 
            std::string backgroundImageFilepath,
            std::string nineSliceImageFilepath,
            std::string fontAssetFilepath,
            int fontSize,
            std::string musicAssetFilepath,
            std::string soundEffectAssetFilepath);
        void init() override;
        // void update(float dt) override;
        // void render() override;
        void shutdown() override;

    private:
        float m_timer = 0.0f;
        GameEngine* m_engine;
        SDL_Renderer* m_renderer = nullptr;
        std::shared_ptr<AssetManager> m_assetManager = nullptr;
        std::vector<Entity> m_options;
        std::string m_backgroundImageFilepath;
        std::shared_ptr<ImageAsset> m_backgroundImage = nullptr;
        std::string m_nineSliceImageFilepath;
        std::shared_ptr<ImageAsset> m_nineSliceImage = nullptr;
        int m_fontSize;
        std::string m_fontAssetFilepath;
        std::shared_ptr<FontAsset> m_fontAsset = nullptr;
        std::string m_musicAssetFilepath;
        std::shared_ptr<MusicAsset> m_musicAsset = nullptr;
        std::string m_soundEffectAssetFilepath;
        std::shared_ptr<SoundEffectAsset> m_soundEffectAsset = nullptr;
        // std::shared_ptr<ImageAsset> m_nineSliceImage = nullptr;
        // NineSlicePanelComponent panelComponent;
        
        void buildBackgroundImage();
        void buildNineSliceMenu();
        InputMap* generateInputMap();
        void setupSystem();
    };

}
