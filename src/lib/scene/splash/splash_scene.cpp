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
// #include "retronomicon/lib/input/input_component.h"
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
	
	SplashScene::SplashScene(GameEngine* engine,std::shared_ptr<ImageAsset> image)
	    : Scene("Splash"), m_engine(engine),m_image(image) {}

	SplashScene::~SplashScene() {
	    // unloadAssets();
	}

	void SplashScene::init() {
		// setup renderer
		std::cout << "[Splash Scene] setup renderer" <<std::endl;
		m_renderer = m_engine->getRenderer();

		// setup systems
		std::cout << "[Splash Scene] setup systems" <<std::endl;
		this->addSystem(std::make_unique<AnimationSystem>());
		this->addSystem(std::make_unique<RenderSystem>(m_renderer));
		this->addSystem(std::make_unique<SceneChangeSystem>(m_engine));

		//setup input system with keymapping
        InputMap* inputMap = new InputMap();
        inputMap->bindAction(SDL_SCANCODE_SPACE, "confirm");
        inputMap->bindAction(SDL_SCANCODE_RETURN, "confirm");
        inputMap->bindAction(SDL_SCANCODE_A, "confirm");
        inputMap->bindAction(SDL_SCANCODE_W, "confirm");
        inputMap->bindAction(SDL_SCANCODE_S, "confirm");
        inputMap->bindAction(SDL_SCANCODE_D, "confirm");
        inputMap->bindAction(SDL_SCANCODE_ESCAPE,"quit");
		this->addSystem(std::make_unique<InputSystem>(inputMap));

		// getWindowDimension
        int windowWidth = Window::getWidth();
        int windowHeight = Window::getHeight();

		// setup logo
		std::cout << "[Splash Scene] create logo entity" <<std::endl;
		Entity* logoEntity = new Entity("logo");

		std::cout << "[Splash Scene] create logo's sprite component" <<std::endl;
		SpriteComponent* logoSpriteComponent = logoEntity->addComponent<SpriteComponent>(m_image);
		
		std::cout << "[Splash Scene] create logo's transform component" <<std::endl;
		//setup position in the middle of the screen.
		TransformComponent* logoTransformComponent = logoEntity->addComponent<TransformComponent>(windowWidth/2,windowHeight/2,1.0f,1.0f);
		// set anchor to middle of the image (just for future proofing in case default value of the anchor not in the middle)
		logoTransformComponent->setAnchor(0.5f,0.5f);

		std::cout << "[Splash Scene] create logo's animation sequence" <<std::endl;
		//create animation frame
		std::vector<AnimationFrame> frames;
		frames.emplace_back(0, 0, m_image->getWidth(), m_image->getHeight(), this->m_duration);

		auto clip = std::make_shared<AnimationClip>(frames, std::string("logo_wait"), false);
		auto logoAnimationComponent = logoEntity->addComponent<AnimationComponent>(clip);
		SplashAnimationListener* listener=  new SplashAnimationListener();
		logoAnimationComponent->setListener(listener);

	    std::cout << "[Splash Scene] create logo's scene change component trigger" <<std::endl;
		logoEntity->addComponent<SceneChangeComponent>("Menu");

	    // std::cout << "[Splash Scene] create input component" <<std::endl;


		std::cout << "[Splash Scene] start the entity" <<std::endl;
		logoEntity->start();


		this->addChildEntity(logoEntity);
	    m_timer = 0.0f;
	    m_finished = false;
	    // loadAssets();
	    setInitialized(true);
	    setActive(true);
	}

	void SplashScene::setOnFinish(std::function<void(const std::string&)> callback) {
	    m_onFinish = std::move(callback);
	}



	// void SplashScene::update(float dt) {
	//     handleInput();
	//     m_timer += dt;
	//     if (m_timer >= m_duration || m_finished) {
	//         m_finished = true;

	//         this->getComponent<SceneChangeComponent>()->triggered = true;
	//         // Change scene to "Menu" if callback is set
	//     }

	//     // std::cout<<"masuk ga?"<< m_timer<<std::endl;
	//     for (auto& system : m_systems) {
	//         // std::cout<<"masuk kok"<<std::endl;
	//         system->update(dt, this);
	//     }            

	// }


	void SplashScene::shutdown() {
	    // unloadAssets();
	    setInitialized(false);
	    setActive(false);
	}

	// void SplashScene::render() {
	//     SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	//     SDL_RenderClear(m_renderer);

	//     if (m_logoTexture) {
	//         int w, h;
	//         SDL_QueryTexture(m_logoTexture, nullptr, nullptr, &w, &h);
	//         SDL_Rect dst = { (Window::getWidth() - w) / 2, (Window::getHeight() - h) / 2, w, h };
	//         SDL_RenderCopy(m_renderer, m_logoTexture, nullptr, &dst);
	//     }

	//     SDL_RenderPresent(m_renderer);
	// }

	bool SplashScene::isFinished() const {
	    return m_finished;
	}

	void SplashScene::handleInput() {
	    SDL_Event event;
	    while (SDL_PollEvent(&event)) {
	        if (event.type == SDL_QUIT ||
	            event.type == SDL_KEYDOWN ||
	            event.type == SDL_MOUSEBUTTONDOWN) {
	            m_finished = true;
	        }
	    }
	}

	void SplashScene::setImage(SDL_Texture* texture){
	    m_logoTexture = texture;
	}

} // namespace retronomicon::platformer::scene
