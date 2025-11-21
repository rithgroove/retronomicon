#include "retronomicon/input/splash/splash_input_action.h"
#include <iostream>

namespace retronomicon::input::splash {

    void SplashInputAction::execute(std::weak_ptr<Entity> entity,
                                    const InputState& state)
    {
        std::cout <<"execute called"<<std::endl;
        // Attempt to lock the entity
        auto e = entity.lock();
        if (!e) {
            std::cerr << "[SplashInputAction] Entity expired (destroyed?) — cannot trigger scene change.\n";
            return;
        }

        // Ensure SceneChangeComponent exists
        if (!e->hasComponent<retronomicon::component::SceneChangeComponent>()) {
            std::cerr << "[SplashInputAction] SceneChangeComponent not found on entity "
                      << e->getName() << "\n";
            return;
        }

        // Retrieve component
        auto comp = e->getComponent<retronomicon::component::SceneChangeComponent>();

        // Trigger the scene change
        comp->trigger();
    }

} // namespace retronomicon::input::splash
