#include <sstream>
#include <memory>
#include <iostream>
#include "retronomicon/animation/splash/splash_animation_listener.h"
#include "retronomicon/component/scene_change_component.h"
#include "retronomicon/entity/entity.h"

namespace retronomicon::animation::splash{
	using retronomicon::entity::Entity;
	using retronomicon::component::SceneChangeComponent;
	void SplashAnimationListener::onAnimationFinished(AnimationComponent* sender){
		auto owner = sender->getOwner();

		if (owner->hasComponent<SceneChangeComponent>()){
			auto scc = owner->getComponent<SceneChangeComponent>();
			scc->trigger();
		}else{
			std::cerr<<"The AnimationComponent's Entity (owner) that this class listen to, does not have SceneChangeComponent sibling.";
		}

	}
    
    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string SplashAnimationListener::to_string() const{
        std::ostringstream oss;
		oss << "[SplashAnimationListener]\n";
        return oss.str();
    }

}


