#pragma once
#include "retronomicon/lib/animation/animation_listener.h"
#include "retronomicon/lib/animation/animation_component.h"

namespace retronomicon::lib::scene::splash{

	using retronomicon::lib::animation::AnimationListener;
	using retronomicon::lib::animation::AnimationComponent;

	class SplashAnimationListener:public AnimationListener{
		public:
			void onAnimationFinished(AnimationComponent* sender) override;
			std::string to_string() const override;
	};


}