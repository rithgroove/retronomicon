#pragma once
#include <memory>
#include <string>
#include <retronomicon/scene/scene.h>
// NOTE: IRenderer lives in retronomicon::graphics per core docs.
#include <retronomicon/graphics/renderer/i_renderer.h>
#include <retronomicon/asset/image_asset.h>

namespace retronomicon::scene::splash {
    using retronomicon::graphics::renderer::IRenderer;
    using retronomicon::asset::ImageAsset;
    using retronomicon::entity::Entity;
    class SplashScene : public retronomicon::scene::Scene{
    public:
        SplashScene(std::shared_ptr<IRenderer> renderer,
                    const std::string& imagePath,
                    const std::string& nextScene = "");

        void start() override;
        void update(float dt) override;
        void shutdown() override;

    private:
        void createLogoEntity();

    private:
        std::shared_ptr<IRenderer> m_renderer;
        std::shared_ptr<ImageAsset> m_logoImage;
        std::shared_ptr<Entity> m_logoEntity;

        std::string m_imagePath;
        std::string m_nextScene;
        float m_elapsedTime = 0.0f;
        float m_duration = 3.0f;
        bool m_skipRequested = false;
    };

} // namespace retronomicon::scene::splash
