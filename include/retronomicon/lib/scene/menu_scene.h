#pragma once
#include <memory>

#include "retronomicon/lib/core/scene.h"
#include "retronomicon/lib/asset/image_asset.h"
namespace retronomicon::lib::scene {
    using retronomicon::lib::asset::ImageAsset;
    class MenuScene : public retronomicon::lib::core::Scene {
    public:
        MenuScene();
        MenuScene(std::shared_ptr<ImageAsset> m_backgroundImage);

        void init() override;
        // void update(float dt) override;
        // void render() override;
        void shutdown() override;

    private:
        float m_timer = 0.0f;
        std::shared_ptr<ImageAsset> m_backgroundImage= nullptr;
    };

}
