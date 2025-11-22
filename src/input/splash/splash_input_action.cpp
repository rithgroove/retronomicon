#include "retronomicon/input/splash/splash_input_action.h"
#include "retronomicon/component/exit_game_component.h"
#include <iostream>

namespace retronomicon::input::splash {
    using namespace retronomicon::component;
    void SplashInputAction::execute(std::weak_ptr<Entity> entity,
                                    std::shared_ptr<InputState> state)
    {
        std::cout <<"execute called"<<std::endl;
        // Attempt to lock the entity
        auto e = entity.lock();
        if (!e) {
            std::cerr << "[SplashInputAction] Entity expired (destroyed?) — cannot trigger scene change.\n";
            return;
        }

        // Ensure SceneChangeComponent exists
        if (state->wasActionJustPressed("confirm")) {
            // Retrieve component
            std::cout <<"confirm called"<<std::endl;
            if (!e->hasComponent<SceneChangeComponent>()) {
                std::cerr << "[SplashInputAction] SceneChangeComponent not found on entity "
                          << e->getName() << "\n";
                return;
            }
            auto comp = e->getComponent<SceneChangeComponent>();

            // Trigger the scene change
            comp->trigger();
        }else if (state->wasActionJustPressed("exit")) {
            // Retrieve component
            std::cout <<"exit called"<<std::endl;
            if (!e->hasComponent<ExitGameComponent>()) {
                std::cerr << "[SplashInputAction] ExitGameComponent not found on entity "
                          << e->getName() << "\n";
                return;
            }
            auto comp = e->getComponent<ExitGameComponent>();

            // Trigger the scene change
            comp->trigger();
        }

    }

} // namespace retronomicon::input::splash
