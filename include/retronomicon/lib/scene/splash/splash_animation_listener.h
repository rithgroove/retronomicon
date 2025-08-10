#pragma once
#include "retronomicon/lib/animation/animation_listener.h"

namespace retronomicon::lib::scene::splash{
	using retronomicon::lib::animation::AnimationListener;
	class SplashAnimationListener:: prublic AnimationListener{
		void onAnimationFinished(AnimationComponent* sender) override;

		std::string to_string() override;
	}


}