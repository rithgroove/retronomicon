#include "retronomicon/input/splash/splash_input_component.h"
#include "retronomicon/component/scene_change_component.h"
#include "retronomicon/entity/entity.h"
namespace retronomicon::input::splash{
	using retronomicon::component::SceneChangeComponent;
	using retronomicon::entity::Entity;

	SplashInputComponent::SplashInputComponent(std::shared_ptr<InputState> state):InputComponent(state){

	}

	// SplashInputComponent::beginFrame(){}

	void SplashInputComponent::update(float dt){
		if (m_inputState->wasActionJustPressed("confirm")){
			auto owner =  this->getOwner();
			auto sceneChangeComponent = owner->getComponent<SceneChangeComponent>();
			sceneChangeComponent->trigger();
		}
	}


}