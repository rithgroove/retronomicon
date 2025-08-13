#include "retronomicon/lib/scene/splash/splash_input_component.h"
#include "retronomicon/lib/scene/scene_change_component.h"
#include "retronomicon/lib/core/entity.h"
namespace retronomicon::lib::scene::splash{
	using retronomicon::lib::scene::SceneChangeComponent;
	using retronomicon::lib::core::Entity;

	SplashInputComponent::SplashInputComponent(){

	}

	// SplashInputComponent::beginFrame(){}

	void SplashInputComponent::updateFromState(InputState* state, float dt){
		if (state->isActionActive("confirm")){
			auto* owner =  this->getOwner();
			auto* sceneChangeComponent = owner->getComponent<SceneChangeComponent>();
			sceneChangeComponent->triggered = true;
		}
	}


}