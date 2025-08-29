#include "retronomicon/lib/scene/splash/splash_scene.h"
#include <SDL_image.h>
#include <SDL_events.h>
#include <iostream> // for debug if needed
#include "retronomicon/lib/scene/scene_change_component.h"
#include "retronomicon/lib/scene/scene_change_system.h"
#include "retronomicon/lib/graphic/window.h"
// Import for the logo
#include "retronomicon/lib/core/entity.h"
#include "retronomicon/lib/core/transform_component.h"
#include "retronomicon/lib/graphic/sprite_component.h"
#include "retronomicon/lib/graphic/render_system.h"
// import for the animation
#include "retronomicon/lib/animation/animation_frame.h"
#include "retronomicon/lib/animation/animation_clip.h"
#include "retronomicon/lib/animation/animation_component.h"
#include "retronomicon/lib/animation/animation_system.h"
#include "retronomicon/lib/scene/splash/splash_animation_listener.h"
// import for input
#include "retronomicon/lib/input/input_system.h"
#include "retronomicon/lib/input/input_map.h"
#include "retronomicon/lib/scene/splash/splash_input_component.h"
#include "retronomicon/lib/input/input_state.h"
#include "retronomicon/lib/input/raw_input.h"

namespace retronomicon::lib::scene::splash {
	using retronomicon::lib::graphic::Window;
	using retronomicon::lib::core::Entity;
	using retronomicon::lib::core::TransformComponent;
	using retronomicon::lib::graphic::SpriteComponent;
	using retronomicon::lib::graphic::RenderSystem;
	using retronomicon::lib::animation::AnimationClip;
	using retronomicon::lib::animation::AnimationFrame;
	using retronomicon::lib::animation::AnimationComponent;
	using retronomicon::lib::animation::AnimationSystem;
	using retronomicon::lib::scene::SceneChangeComponent;
	using retronomicon::lib::scene::SceneChangeSystem;
	using retronomicon::lib::input::InputMap;
	using retronomicon::lib::input::InputSystem;
	// using retronomicon::lib::graphic::SpriteComponent;
	
	SplashScene::SplashScene(GameEngine* engine,std::shared_ptr<ImageAsset> image, const std::string nextScene)
	    : Scene("Splash"), m_engine(engine),m_image(image),m_nextScene(nextScene) {}

	SplashScene::~SplashScene() {
	    // unloadAssets();
	}

	InputMap* SplashScene::generateInputMap(){
		std::cout << "[Splash Scene] setup input map" <<std::endl;
        InputMap* inputMap = new InputMap();
        inputMap->bindAction(SDL_SCANCODE_SPACE, "confirm");
        inputMap->bindAction(SDL_SCANCODE_RETURN, "confirm");
        inputMap->bindAction(SDL_SCANCODE_A, "confirm");
        inputMap->bindAction(SDL_SCANCODE_W, "confirm");
        inputMap->bindAction(SDL_SCANCODE_S, "confirm");
        inputMap->bindAction(SDL_SCANCODE_D, "confirm");
        inputMap->bindAction(SDL_SCANCODE_ESCAPE,"quit");
		return inputMap;		
	}

	void SplashScene::setupSystem(){
		//setup input map and update inputstate to use thesep
        auto* inputState = m_engine->getInputState();
        inputState->setInputMap(this->generateInputMap());

		// setup systems
		std::cout << "[Splash Scene] setup systems" <<std::endl;

		// setup animation system used for timer until changing to next scene
		this->addSystem(std::make_unique<AnimationSystem>());
		// setup render system used to draw to screen
		this->addSystem(std::make_unique<RenderSystem>(m_renderer));
		// setup scene change system to trigger scene change to the next one
		this->addSystem(std::make_unique<SceneChangeSystem>(m_engine));
		// setup input system to skip to next scene
		this->addSystem(std::make_unique<InputSystem>(inputState));
	}

	void SplashScene::setupLogo(){
		// ------------- get important variable----------------------
        int windowWidth = Window::getWidth();
        int windowHeight = Window::getHeight();

		// ------------- setup logo ----------------------
		std::cout << "[Splash Scene] create logo entity" <<std::endl;
		Entity* logoEntity = new Entity("logo");

		// ---------------- setup sprite component --------------------------
		SpriteComponent* logoSpriteComponent = logoEntity->addComponent<SpriteComponent>(m_image);
		
		// ---------------- setup transform component --------------------------
		TransformComponent* logoTransformComponent = logoEntity->addComponent<TransformComponent>(windowWidth/2,windowHeight/2,1.0f,1.0f);
		logoTransformComponent->setRotation(0.0f);
		logoTransformComponent->setAnchor(0.5f,0.5f);

		// ---------------- setup scene change component --------------------------
		logoEntity->addComponent<SceneChangeComponent>(m_nextScene);

		// ---------------- setup animation component using m_duration as wait time ------------------------
		std::vector<AnimationFrame> frames; // array of frame
		frames.emplace_back(0, 0, m_image->getWidth(), m_image->getHeight(), this->m_duration); // create a single frame 
		auto clip = std::make_shared<AnimationClip>(frames, std::string("logo_wait"), false);  // create animation clip 
		auto logoAnimationComponent = logoEntity->addComponent<AnimationComponent>(clip); // create animation component
		logoAnimationComponent->setListener(new SplashAnimationListener()); // setup listener so it set scene changecomponent to true

		// ---------------- setup splash input component to trigger scene change after any mapped input --------------------------
	    logoEntity->addComponent<SplashInputComponent>();

	    // ---------------- start the entity so it could perform properly -----------------------
		logoEntity->start();

		// ---------------- add logoEntity as child of this scene --------------------
		this->addChildEntity(logoEntity);
	}

	void SplashScene::init() {
		if (!m_isInitialized){
			m_renderer = m_engine->getRenderer();
			this->setupSystem();

			this->setupLogo();
		}
	    setInitialized(true);
	    setActive(true);
	}
	
	// void SplashScene::deinit() {
	// 	if (!m_isInitialized){
	// 		m_renderer = m_engine->getRenderer();
	// 		this->setupSystem();

	// 		this->setupLogo();
	// 	}
	//     setInitialized(true);
	//     setActive(true);
	// }

	void SplashScene::shutdown() {
	    // unloadAssets();
	    setActive(false);
	}


} // namespace retronomicon::platformer::scene
