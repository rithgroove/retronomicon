#include "retronomicon/lib/scripting/script_system.h"
#include "retronomicon/lib/scripting/iscript_engine.h"

namespace retronomicon::lib::scripting {

    ScriptSystem::ScriptSystem() = default;

    /* ---------------------------------------------------------- */

    void ScriptSystem::registerEngine(
        retronomicon::lib::core::component::ScriptLanguage lang,
        std::shared_ptr<IScriptEngine> engine
    ) {
        engines_[lang] = std::move(engine);
    }

    /* ---------------------------------------------------------- */

    void ScriptSystem::start() {
        // Example ECS logic if registry is set:
        /*
        if (!registry_) return;

        auto view = registry_->view<ScriptComponent>();
        for (auto entity : view) {
            auto& comp = view.get<ScriptComponent>(entity);
            if (!comp.isEnabled()) continue;

            auto it = engines_.find(comp.getLanguage());
            if (it != engines_.end() && it->second) {
                it->second->runStart(entity, comp);
            }
        }
        */
    }

    /* ---------------------------------------------------------- */

    void ScriptSystem::update(float deltaTime) {
        // Example ECS logic if registry is set:
        /*
        if (!registry_) return;

        auto view = registry_->view<ScriptComponent>();
        for (auto entity : view) {
            auto& comp = view.get<ScriptComponent>(entity);
            if (!comp.isEnabled()) continue;

            auto it = engines_.find(comp.getLanguage());
            if (it != engines_.end() && it->second) {
                it->second->runUpdate(entity, comp, deltaTime);
            }
        }
        */
    }

    /* ---------------------------------------------------------- */

    void ScriptSystem::broadcastEvent(const std::string& eventName) {
        // Example ECS logic if registry is set:
        /*
        if (!registry_) return;

        auto view = registry_->view<ScriptComponent>();
        for (auto entity : view) {
            auto& comp = view.get<ScriptComponent>(entity);
            if (!comp.isEnabled()) continue;

            auto it = engines_.find(comp.getLanguage());
            if (it != engines_.end() && it->second) {
                it->second->runEvent(entity, comp, eventName);
            }
        }
        */
    }

    /* ---------------------------------------------------------- */

    // Optional registry injection if you're using entt
    /*
    void ScriptSystem::setRegistry(entt::registry* registry) {
        registry_ = registry;
    }
    */

} // namespace retronomicon::lib::scripting
