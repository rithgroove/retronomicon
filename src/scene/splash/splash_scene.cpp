#include "retronomicon/scene/splash/splash_scene.h"

#include "retronomicon/component/transform_component.h"
#include "retronomicon/component/renderable.h"
#include "retronomicon/component/animation_component.h"
#include "retronomicon/component/scene_change_component.h"
#include "retronomicon/animation/splash/splash_animation_listener.h"
#include "retronomicon/system/animation_system.h"
#include "retronomicon/system/input_system.h"
#include "retronomicon/system/scene_change_system.h"
#include "retronomicon/system/generic_system.h"
#include "retronomicon/component/sprite_component.h"
#include "retronomicon/component/bound_component.h"
#include <iostream>
namespace retronomicon::scene::splash{
    using namespace retronomicon::component;
    using namespace retronomicon::system;
    using retronomicon::animation::splash::SplashAnimationListener;

    SplashScene::SplashScene(std::shared_ptr<GameEngine> gameEngine,
                             std::shared_ptr<TextureManager> textureManager,
                             const std::string& imagePath,
                             const std::string& nextScene)
        : Scene("SplashScene")
        , m_gameEngine(gameEngine)
        , m_renderer(gameEngine->getRenderer())
        , m_textureManager(textureManager)
        , m_imagePath(imagePath)
        , m_nextScene(nextScene)
    {}

    void SplashScene::start() {
        // Always call base version
        Scene::start();

        // Construct ImageAsset directly — it loads during construction
        try {
            m_logoImage = std::make_shared<ImageAsset>(m_imagePath);
        } catch (const std::exception& e) {
            std::cerr << "[SplashScene] Failed to create ImageAsset: "
                      << e.what() << " (" << m_imagePath << ")\n";
        }

        createLogoEntity();

        // Register systems in correct order
        addSystem(std::make_unique<AnimationSystem>());
        addSystem(std::make_unique<GenericSystem<SpriteComponent>>());
// GenericSystem<TransformComponent> transformSystem;
        addSystem(std::make_unique<InputSystem>());
        addSystem(std::make_unique<SceneChangeSystem>(m_gameEngine));

        m_isActive = true;
    }

    void SplashScene::createLogoEntity() {
        m_logoEntity = std::make_shared<Entity>("SplashLogo");


        int windowWidth = m_renderer->getWidth();
        int windowHeight = m_renderer->getHeight();

        // Place logo at center (temporary)
        auto transformComponent = m_logoEntity->addComponent<TransformComponent>(windowWidth/2.0f, windowHeight/ 2.0f);
        auto boundComponent = m_logoEntity->addComponent<BoundComponent>(400, 300);
        transformComponent->setScale(1.0f,1.0f);

        // Attach renderable using the image asset
        auto spriteComponent = m_logoEntity->addComponent<SpriteComponent>(m_logoImage);
        spriteComponent->generateTexture(m_textureManager);

        // Simple animation + scene change
        // ---------------- setup animation component using m_duration as wait time ------------------------
        std::vector<AnimationFrame> frames; // array of frame
        frames.emplace_back(0, 0, m_logoImage->getWidth(), m_logoImage->getHeight(), this->m_duration); // create a single frame 
        auto clip = std::make_shared<AnimationClip>(frames, std::string("logo_wait"), false);  // create animation clip 
        auto logoAnimationComponent = m_logoEntity->addComponent<AnimationComponent>(clip); // create animation component
        logoAnimationComponent->setListener(new SplashAnimationListener()); // setup listener so it set scene changecomponent to true

        m_logoEntity->addComponent<SceneChangeComponent>(m_nextScene);
        m_logoEntity->start();
        addChildEntity(m_logoEntity);
    }

    void SplashScene::update(float dt) {
        Scene::update(dt);

        m_elapsedTime += dt;

        if (m_skipRequested || m_elapsedTime >= m_duration) {
            if (auto sceneChange = m_logoEntity->getComponent<SceneChangeComponent>()) {
                sceneChange->trigger();
            }
        }
    }
    
    void SplashScene::shutdown() {
        m_elapsedTime = 0.0;
        m_logoEntity.reset();
        m_logoImage.reset();
        Scene::shutdown();
    }

}
