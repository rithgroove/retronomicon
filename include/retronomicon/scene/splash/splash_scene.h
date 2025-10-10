#pragma once

#include <memory>
#include <string>
#include <functional>
#include <vector>

#include "retronomicon/scene/scene.h"
#include "retronomicon/asset/image_asset.h"
#include "retronomicon/graphics/renderer/i_renderer.h"

namespace retronomicon::scene::splash {

using retronomicon::asset::AssetManager;
using retronomicon::asset::ImageAsset;
using retronomicon::graphics::renderer::IRenderer;

/**
 * @brief SplashScene
 *
 * Displays a splash/logo screen for a defined duration.
 * Uses ECS systems for animation, scene transition, and input.
 * Rendering is delegated to an injected IRenderer instance.
 */
class SplashScene : public retronomicon::scene::Scene {
public:
    /**
     * @brief Construct a SplashScene.
     *
     * @param assetManager Shared AssetManager for loading image assets.
     * @param renderer     Pointer to active renderer backend (OpenGL, SDL, etc.)
     * @param imagePath    Path or identifier for the splash image.
     * @param imageKey     Asset key used for caching / reloading.
     * @param nextScene    Scene to load after splash completes.
     * @param durationSec  How long to display the splash in seconds.
     */
    explicit SplashScene(std::shared_ptr<AssetManager> assetManager,
                         std::shared_ptr<IRenderer> renderer,
                         std::string imagePath,
                         std::string imageKey,
                         std::string nextScene = "Menu",
                         float durationSec = 3.0f);

    ~SplashScene() override;

    // === Lifecycle ===
    void start() override;        // Setup ECS systems + logo entity
    void render() override;       // Delegate to IRenderer + ECS RenderManager
    void shutdown() override;     // Cleanup

    /**
     * @brief Optional callback when the splash finishes (animation or input).
     */
    void setOnFinishedCallback(std::function<void()> cb) { onFinished = std::move(cb); }

private:
    void setupSystems();
    void setupLogoEntity();

    std::shared_ptr<AssetManager> m_assetManager;
    std::shared_ptr<IRenderer> m_renderer;   ///< Abstract renderer backend

    std::unique_ptr<ImageAsset> m_image;

    std::string m_imagePath;
    std::string m_imageKey;
    std::string m_nextScene;

    float m_durationSec;
    bool  m_isInitialized = false;

    std::function<void()> onFinished;
};

} // namespace retronomicon::scene::splash
