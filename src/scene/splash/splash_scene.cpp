#include "retronomicon/scene/splash/splash_scene.h"

#include "retronomicon/component/transform_component.h"
#include "retronomicon/component/renderable.h"
#include "retronomicon/component/animation_component.h"
#include "retronomicon/component/scene_change_component.h"
#include "retronomicon/system/animation_system.h"
#include "retronomicon/system/input_system.h"
#include "retronomicon/system/scene_change_system.h"

#include <iostream>
namespace retronomicon::scene::splash{
    using namespace retronomicon::component;
    using namespace retronomicon::system;

    SplashScene::SplashScene(std::shared_ptr<IRenderer> renderer,
                             const std::string& imagePath,
                             const std::string& nextScene)
        : Scene("SplashScene")
        , m_renderer(std::move(renderer))
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

        // createLogoEntity();

        // Register systems in correct order
        // addSystem(std::make_unique<animation::AnimationSystem>());
        // addSystem(std::make_unique<input::InputSystem>());
        // addSystem(std::make_unique<scene::SceneChangeSystem>());

        m_isActive = true;
    }

    void SplashScene::createLogoEntity() {
        m_logoEntity = std::make_shared<Entity>("SplashLogo");

        // Place logo at center (temporary)
        m_logoEntity->addComponent<TransformComponent>(0.0f, 0.0f);

        // Attach renderable using the image asset
        // m_logoEntity->addComponent<Sp>(m_logoImage);

        // Simple animation + scene change// ---------------- setup animation component using m_duration as wait time ------------------------
        std::vector<AnimationFrame> frames; // array of frame
        frames.emplace_back(0, 0, m_logoImage->getWidth(), m_logoImage->getHeight(), this->m_duration); // create a single frame 
        auto clip = std::make_shared<AnimationClip>(frames, std::string("logo_wait"), false);  // create animation clip 
        auto logoAnimationComponent = m_logoEntity->addComponent<AnimationComponent>(clip); // create animation component
        // logoAnimationComponent->setListener(new SplashAnimationListener()); // setup listener so it set scene changecomponent to true

        m_logoEntity->addComponent<SceneChangeComponent>(m_nextScene);

        addChildEntity(m_logoEntity);
    }

    void SplashScene::update(float dt) {
        Scene::update(dt);

        m_elapsedTime += dt;

        if (m_skipRequested || m_elapsedTime >= 3.0f) {
            if (auto sceneChange = m_logoEntity->getComponent<SceneChangeComponent>()) {
                sceneChange->trigger();
            }
        }
    }

    void SplashScene::render() {
        // // Let base render manager traverse scene hierarchy
        // m_renderManager.render(shared_from_this());

        // // Delegate to backend renderer for frame presentation
        // if (m_renderer) {
        //     m_renderer->render();
        // }
    }

    void SplashScene::shutdown() {
        m_logoEntity.reset();
        m_logoImage.reset();
        Scene::shutdown();
    }

}
