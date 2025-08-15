#pragma once
#include <memory>
#include <vector>
#include "retronomicon/lib/core/scene.h"
#include "retronomicon/lib/asset/image_asset.h"
#include "retronomicon/lib/asset/font_asset.h"
#include "retronomicon/lib/engine/game_engine.h"
#include "menu_option.h"

namespace retronomicon::lib::scene::menu{
    using retronomicon::lib::asset::ImageAsset;
    using retronomicon::lib::asset::FontAsset;
    using retronomicon::lib::engine::GameEngine;
    class MenuScene : public retronomicon::lib::core::Scene {
    public:
        MenuScene();
        MenuScene(GameEngine* engine,std::shared_ptr<ImageAsset> backgroundImage,std::shared_ptr<FontAsset> fontAsset);


        void createMenu(std::shared_ptr<ImageAsset> nineSliceImage,std::shared_ptr<FontAsset> fontAsset);
        void init() override;
        // void update(float dt) override;
        // void render() override;
        void shutdown() override;

    private:
        float m_timer = 0.0f;
        GameEngine* m_gameEngine;
        std::vector<MenuOption> m_options;
        std::shared_ptr<ImageAsset> m_backgroundImage = nullptr;
        std::shared_ptr<ImageAsset> m_nineSliceImage = nullptr;
        std::shared_ptr<FontAsset> m_fontAsset = nullptr;
        // std::shared_ptr<ImageAsset> m_nineSliceImage = nullptr;
        // NineSlicePanelComponent panelComponent;
        
        InputMap* generateInputMap();
        void setupSystem();
    };

}
