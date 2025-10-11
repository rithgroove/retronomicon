#pragma once
#include <memory>
#include <string>
#include <retronomicon/scene/scene.h>
#include <retronomicon/graphics/renderer/i_renderer.h>
#include <retronomicon/asset/image_asset.h>

namespace retronomicon::scene::splash {

class SplashScene : public Scene {
public:
    SplashScene(std::shared_ptr<graphics::IRenderer> renderer,
                const std::string& imagePath,
                const std::string& nextScene = "");

    void start() override;
    void update(float dt) override;
    void render() override;
    void shutdown() override;

private:
    void createLogoEntity();

private:
    std::shared_ptr<graphics::IRenderer> m_renderer;
    std::shared_ptr<asset::ImageAsset> m_logoImage;
    std::shared_ptr<Entity> m_logoEntity;

    std::string m_imagePath;
    std::string m_nextScene;
    float m_elapsedTime = 0.0f;
    bool m_skipRequested = false;
};

} // namespace retronomicon::scene::splash
