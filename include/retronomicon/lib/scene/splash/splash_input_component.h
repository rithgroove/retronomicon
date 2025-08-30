#pragma once
#include <memory>
#include "retronomicon/lib/input/input_component.h"
#include "retronomicon/lib/input/input_state.h"
namespace retronomicon::lib::scene::splash{

	using retronomicon::lib::input::InputComponent;
	using retronomicon::lib::input::InputState;

	class SplashInputComponent:public InputComponent{
		public:
	        SplashInputComponent();
			void updateFromState(std::shared_ptr<InputState> state, float dt) override;
	};


}