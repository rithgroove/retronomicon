#pragma once
#include <memory>
#include <string>
#include <retronomicon/scene/scene.h>
// NOTE: IRenderer lives in retronomicon::graphics per core docs.
#include <retronomicon/graphics/renderer/i_renderer.h>
#include <retronomicon/asset/image_asset.h>
#include "retronomicon/manager/texture_manager.h"
#include "retronomicon/engine/game_engine.h"
#include "retronomicon/input/input_map.h"
#include "retronomicon/input/raw_input.h"
#include "retronomicon/asset/sound_effect_asset.h"

namespace retronomicon::scene::menu {
    using retronomicon::graphics::renderer::IRenderer;
    using retronomicon::asset::ImageAsset;
    using retronomicon::entity::Entity;
    using retronomicon::manager::TextureManager;
    using retronomicon::input::InputMap;
    using retronomicon::input::RawInput;
    using retronomicon::engine::GameEngine;
    using retronomicon::asset::SoundEffectAsset;
    class MenuScene : public retronomicon::scene::Scene{
    public:
        MenuScene(std::shared_ptr<GameEngine> gameEngine,
                    std::shared_ptr<TextureManager> textureManager,
                    const std::string& imagePath);

        void start() override;
        void update(float dt) override;
        void shutdown() override;

        void setSFX(std::shared_ptr<SoundEffectAsset> sfx){m_sfx = sfx;}
        void setNineSliceImage(const std::string& imagePath){
            m_nineSliceImage = std::make_shared<ImageAsset>(imagePath);
        }

    protected:
        void initiateEntities();
        void initiateSystems();
        void buildNineSliceMenu();
        std::shared_ptr<GameEngine> m_gameEngine;
        std::shared_ptr<IRenderer> m_renderer;
        std::shared_ptr<ImageAsset> m_backgroundImage;
        std::shared_ptr<ImageAsset> m_nineSliceImage;
        std::shared_ptr<Entity> m_backgroundEntity;
        std::shared_ptr<InputMap> m_inputMap;
        std::shared_ptr<RawInput> m_rawInput;
        std::shared_ptr<TextureManager> m_textureManager;
        std::shared_ptr<SoundEffectAsset> m_sfx;

        std::string m_imagePath;
        std::string m_nextScene;
        float m_elapsedTime = 0.0f;
        float m_duration = 3.0f;
        bool m_skipRequested = false;
    };

} // namespace retronomicon::scene::splash
