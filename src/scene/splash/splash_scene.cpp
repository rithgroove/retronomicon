#include "retronomicon/scene/splash/splash_scene.h"

// ECS / Scene / Components
#include "retronomicon/core/ecs/entity.h"
#include "retronomicon/core/ecs/transform_component.h"
#include "retronomicon/core/ecs/renderable.h"
#include "retronomicon/scene/scene_change_component.h"

// Animation
#include "retronomicon/animation/animation_clip.h"
#include "retronomicon/animation/animation_frame.h"
#include "retronomicon/animation/animation_component.h"
#include "retronomicon/animation/animation_system.h"
#include "retronomicon/scene/splash/splash_animation_listener.h"

// Input
#include "retronomicon/input/input_system.h"
#include "retronomicon/input/input_state.h"
#include "retronomicon/scene/splash/splash_input_component.h"

// Graphics
#include "retronomicon/graphics/renderer/i_renderer.h"

// SceneChange system
#include "retronomicon/scene/scene_change_system.h"

#include <iostream>

using namespace retronomicon::core::ecs;
using retronomicon::animation::AnimationSystem;
using retronomicon::animation::AnimationClip;
using retronomicon::animation::AnimationFrame;
using retronomicon::animation::AnimationComponent;
using retronomicon::scene::SceneChangeSystem;
using retronomicon::scene::SceneChangeComponent;
using retronomicon::input::InputSystem;
using retronomicon::input::InputState;
using retronomicon::scene::splash::SplashInputComponent;
using retronomicon::scene::splash::SplashAnimationListener;
using retronomicon::graphics::renderer::IRenderer;

namespace retronomicon::scene::splash {

/*---------------------------------------------------------------
 * Constructor / Destructor
 *-------------------------------------------------------------*/
SplashScene::SplashScene(std::shared_ptr<AssetManager> assetManager,
                         std::string imagePath,
                         std::string imageKey,
                         std::string nextScene,
                         float durationSec)
    : Scene("Splash"),
      m_assetManager(std::move(assetManager)),
      m_imagePath(std::move(imagePath)),
      m_imageKey(std::move(imageKey)),
      m_nextScene(std::move(nextScene)),
      m_durationSec(durationSec) {}

SplashScene::~SplashScene() {
    shutdown();
}

/*---------------------------------------------------------------
 * Lifecycle
 *-------------------------------------------------------------*/
void SplashScene::start() {
    if (m_isInitialized)
        return;

    std::cout << "[SplashScene] start()" << std::endl;

    // Setup ECS systems (excluding render, which is now backend-controlled)
    setupSystems();

    // Load splash image and create entity
    setupLogoEntity();

    m_isInitialized = true;
    setActive(true);
}

void SplashScene::shutdown() {
    std::cout << "[SplashScene] shutdown()" << std::endl;
    Scene::shutdown();
    setActive(false);
    m_isInitialized = false;
}

/*---------------------------------------------------------------
 * Systems Setup
 *-------------------------------------------------------------*/
void SplashScene::setupSystems() {
    std::cout << "[SplashScene] Setting up ECS systems" << std::endl;

    // Core systems that are backend-independent
    addSystem(std::make_unique<AnimationSystem>());
    addSystem(std::make_unique<SceneChangeSystem>());
    addSystem(std::make_unique<InputSystem>());

    // Rendering is handled externally via IRenderer; Scene::render() will call it.
}

/*---------------------------------------------------------------
 * Logo Entity Setup
 *-------------------------------------------------------------*/
void SplashScene::setupLogoEntity() {
    std::cout << "[SplashScene] Creating splash logo entity" << std::endl;

    // Load the image asset
    m_image = m_assetManager->loadImage(m_imagePath, m_imageKey);
    if (!m_image) {
        std::cerr << "[SplashScene] Failed to load splash image from path: " << m_imagePath << std::endl;
        return;
    }

    // Create logo entity
    auto* logoEntity = new Entity("logo");

    // Add renderable using the image asset
    auto* renderable = logoEntity->addComponent<Renderable>(m_image);

    // Add transform
    auto* transform = logoEntity->addComponent<TransformComponent>();
    transform->setAnchor(0.5f, 0.5f); // Centered by default

    // Scene change trigger
    logoEntity->addComponent<SceneChangeComponent>(m_nextScene);

    // Animation: use splash duration as a wait timer
    std::vector<AnimationFrame> frames;
    frames.emplace_back(0, 0, m_image->getWidth(), m_image->getHeight(), m_durationSec);
    auto clip = std::make_shared<AnimationClip>(frames, "logo_wait", false);

    auto* animation = logoEntity->addComponent<AnimationComponent>(clip);
    animation->setListener(new SplashAnimationListener());

    // Input component for skipping
    logoEntity->addComponent<SplashInputComponent>();

    // Start entity to initialize its components
    logoEntity->start();

    // Add as child of this Scene
    addChildEntity(logoEntity);

    std::cout << "[SplashScene] Logo entity setup complete" << std::endl;
}

/*---------------------------------------------------------------
 * Rendering Delegation
 *-------------------------------------------------------------*/
void SplashScene::render() {
    // Instead of having a RenderSystem, we rely on an external IRenderer instance
    // that the engine layer calls between scene updates.
    // The RenderManager (from base Scene) will still traverse and draw entities
    // using their Renderable components.

    // Example call:
    // if (renderer) renderer->render();

    Scene::render();
}

} // namespace retronomicon::scene::splash
