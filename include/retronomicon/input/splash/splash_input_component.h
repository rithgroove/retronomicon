#pragma once
#include <memory>
#include "retronomicon/component/input_component.h"
#include "retronomicon/input/input_state.h"
namespace retronomicon::input::splash{

	using retronomicon::component::InputComponent;
	using retronomicon::input::InputState;

	class SplashInputComponent:public InputComponent{
		public:
	        SplashInputComponent(std::shared_ptr<InputState> state);
			void update(float dt) override;
	};


}