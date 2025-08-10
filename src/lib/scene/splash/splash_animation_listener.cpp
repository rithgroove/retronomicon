#include <sstream>
#include <memory>
#include "retronomicon/lib/scene/splash_animation_listener.h"
#include "retronomicon/lib/scene/scene_change_component.h"
#include "retronomicon/lib/core/entity.h"

namespace retronomicon::lib::scene::splash{
	using retronomicon::lib::core::Entity;
	using retronomicon::lib::scene::SceneChangeComponent;
	void SplashAnimationListener::onAnimationFinished(AnimationComponent* sender) override{
		Entity *owner = sender->getOwner();

		if (owner->hasComponent<SceneChangeComponent>()){
			std::shared_ptr<SceneChangeComponent> scc = owner->getComponent<SceneChangeComponent>();
			scc.triggered = true;
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


