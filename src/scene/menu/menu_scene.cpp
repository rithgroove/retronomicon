#include "retronomicon/scene/menu/menu_scene.h"

#include "retronomicon/component/transform_component.h"
#include "retronomicon/component/renderable.h"
#include "retronomicon/component/animation_component.h"
#include "retronomicon/component/scene_change_component.h"
#include "retronomicon/component/sound_effect_component.h"
#include "retronomicon/animation/splash/splash_animation_listener.h"
#include "retronomicon/system/animation_system.h"
#include "retronomicon/system/input_system.h"
#include "retronomicon/system/scene_change_system.h"
#include "retronomicon/system/exit_game_system.h"
#include "retronomicon/system/generic_system.h"
#include "retronomicon/system/audio_system.h"
#include "retronomicon/component/sprite_component.h"
#include "retronomicon/component/bound_component.h"
#include "retronomicon/component/exit_game_component.h"
#include "retronomicon/input/splash/splash_input_action.h"

#include <iostream>
namespace retronomicon::scene::menu{
    using namespace retronomicon::component;
    using namespace retronomicon::system;
    using retronomicon::input::splash::SplashInputAction;
    using retronomicon::animation::splash::SplashAnimationListener;

    MenuScene::MenuScene(std::shared_ptr<GameEngine> gameEngine,
                             std::shared_ptr<TextureManager> textureManager,
                             const std::string& imagePath)
        : Scene("MenuScene")
        , m_gameEngine(gameEngine)
        , m_renderer(gameEngine->getRenderer())
        , m_textureManager(textureManager)
        , m_inputMap(gameEngine->getInputMap())
        , m_rawInput(gameEngine->getRawInput())
        , m_imagePath(imagePath)
    {}

    void MenuScene::start() {
        // Always call base version
        Scene::start();

        // Construct ImageAsset directly — it loads during construction
        try {
            m_backgroundImage = std::make_shared<ImageAsset>(m_imagePath);
        } catch (const std::exception& e) {
            std::cerr << "[Menu Scene] Failed to create ImageAsset: "
                      << e.what() << " (" << m_imagePath << ")\n";
        }

        initiateEntities();
        initiateSystems();
        m_isActive = true;
    }

    void MenuScene::initiateSystems(){
        // Register systems in correct order
        addSystem(std::make_unique<AnimationSystem>());
        addSystem(std::make_unique<InputSystem>(m_gameEngine->getInputState()));
        addSystem(std::make_unique<GenericSystem<SpriteComponent>>());
        addSystem(std::make_unique<AudioSystem>(m_gameEngine->getAudioPlayer()));
        addSystem(std::make_unique<ExitGameSystem>(m_gameEngine));
        addSystem(std::make_unique<SceneChangeSystem>(m_gameEngine));
    }

    void MenuScene::initiateEntities() {
        m_backgroundEntity = std::make_shared<Entity>("SplashLogo");

        int windowWidth = m_renderer->getWidth();
        int windowHeight = m_renderer->getHeight();

        // Place logo at center (temporary)
        auto transformComponent = m_backgroundEntity->addComponent<TransformComponent>(windowWidth/2.0f, windowHeight/ 2.0f);
        auto boundComponent = m_backgroundEntity->addComponent<BoundComponent>(windowWidth, windowHeight);
        boundComponent->setScaleMode(ScaleMode::Cover);
        transformComponent->setScale(1.0f,1.0f);

        // Attach renderable using the image asset
        auto backgroundComponent = m_backgroundEntity->addComponent<SpriteComponent>(m_backgroundImage);
        backgroundComponent->generateTexture(m_textureManager);

        // // Simple animation + scene change
        // // ---------------- setup animation component using m_duration as wait time ------------------------
        // std::vector<AnimationFrame> frames; // array of frame
        // frames.emplace_back(0, 0, m_backgroundImage->getWidth(), m_backgroundImage->getHeight(), this->m_duration); // create a single frame 
        // auto clip = std::make_shared<AnimationClip>(frames, std::string("logo_wait"), false);  // create animation clip 
        // auto logoAnimationComponent = m_backgroundEntity->addComponent<AnimationComponent>(clip); // create animation component
        // logoAnimationComponent->setListener(new SplashAnimationListener()); // setup listener so it set scene changecomponent to true

        m_backgroundEntity->addComponent<SceneChangeComponent>(m_nextScene);
        m_backgroundEntity->addComponent<ExitGameComponent>();
        
        auto inputComp = m_backgroundEntity->addComponent<InputComponent>();

        // // Bind the action named "Confirm"
        // inputComp->bindAction(
        //     "confirm",
        //     std::make_unique<SplashInputAction>() // pass next scene
        // );

        // inputComp->bindAction(
        //     "exit",
        //     std::make_unique<SplashInputAction>() // pass next scene
        // );

        // if (m_sfx){
        //     std::cout<<"setup sfx"<<std::endl;
        //     auto sfx = m_logoEntity->addComponent<SoundEffectComponent>(m_sfx.get(),0);
        //     sfx->play();
        // }

        addChildEntity(m_backgroundEntity);
        m_backgroundEntity->start();
        // continueComponent
    }

    void MenuScene::update(float dt) {
        Scene::update(dt);

        m_elapsedTime += dt;

        if (m_skipRequested || m_elapsedTime >= m_duration) {
            if (auto sceneChange = m_backgroundEntity->getComponent<SceneChangeComponent>()) {
                sceneChange->trigger();
            }
        }
    }
    
    void MenuScene::shutdown() {
        m_elapsedTime = 0.0;
        m_backgroundEntity.reset();
        m_backgroundImage.reset();
        Scene::shutdown();
    }

}
