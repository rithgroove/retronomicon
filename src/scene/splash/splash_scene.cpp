#include <retronomicon/scene/splash/splash_scene.h>
#include <retronomicon/core/ecs/transform_component.h>
#include <retronomicon/core/ecs/renderable_component.h>
#include <retronomicon/core/ecs/animation_component.h>
#include <retronomicon/core/ecs/scene_change_component.h>
#include <retronomicon/core/ecs/systems/animation_system.h>
#include <retronomicon/core/ecs/systems/input_system.h>
#include <retronomicon/core/ecs/systems/scene_change_system.h>

using namespace retronomicon::scene::splash;
using namespace retronomicon::core::ecs;

SplashScene::SplashScene(std::shared_ptr<graphics::IRenderer> renderer,
                         const std::string& imagePath,
                         const std::string& nextScene)
    : m_renderer(std::move(renderer))
    , m_imagePath(imagePath)
    , m_nextScene(nextScene)
{}

void SplashScene::start() {
    // Load image asset (engine-agnostic)
    m_logoImage = std::make_shared<asset::ImageAsset>();
    if (!m_logoImage->load(m_imagePath)) {
        // log error, but continue
    }

    // Create ECS entity for logo
    createLogoEntity();

    // Attach systems
    addSystem(std::make_shared<AnimationSystem>());
    addSystem(std::make_shared<InputSystem>());
    addSystem(std::make_shared<SceneChangeSystem>());
}

void SplashScene::createLogoEntity() {
    m_logoEntity = std::make_shared<Entity>();

    // Position logo at center (temporary, 0,0)
    auto transform = m_logoEntity->addComponent<TransformComponent>(Vec2{0.0f, 0.0f});
    m_logoEntity->addComponent<RenderableComponent>(m_logoImage);
    m_logoEntity->addComponent<AnimationComponent>(3.0f /* duration seconds */);
    m_logoEntity->addComponent<SceneChangeComponent>(m_nextScene);

    addChild(m_logoEntity);
}

void SplashScene::update(float dt) {
    m_elapsedTime += dt;

    // Skip check via InputSystem or a flag updated externally
    if (m_skipRequested || m_elapsedTime >= 3.0f) {
        // Trigger scene transition
        auto sceneChange = m_logoEntity->getComponent<SceneChangeComponent>();
        if (sceneChange) {
            sceneChange->trigger();
        }
    }

    for (auto& sys : m_systems)
        sys->update(dt, shared_from_this());
}

void SplashScene::render() {
    m_renderManager.render(shared_from_this(), m_renderer);
}

void SplashScene::shutdown() {
    m_logoEntity.reset();
    m_logoImage.reset();
    m_systems.clear();
    clearChildren();
}
