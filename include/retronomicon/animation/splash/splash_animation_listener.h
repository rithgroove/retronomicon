#pragma once
#include "retronomicon/animation/animation_listener.h"
#include "retronomicon/component/animation_component.h"

namespace retronomicon::animation::splash{

	using retronomicon::animation::AnimationListener;
	using retronomicon::component::AnimationComponent;

	class SplashAnimationListener:public AnimationListener{
		public:
			void onAnimationFinished(AnimationComponent* sender) override;
			std::string to_string() const override;
	};


}