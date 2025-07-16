#include "retronomicon/lib/scripting/script_system.h"
#include "retronomicon/lib/scripting/iscript_engine.h"   // defines IScriptEngine

#include <memory>
namespace retronomicon::lib::scripting{
    using std::shared_ptr;
    using std::string;
    // ScriptSystem::ScriptSystem(){}

    /* ---------------------------------------------------------- */

    void ScriptSystem::registerEngine(ScriptLanguage lang,
                                      shared_ptr<IScriptEngine> engine)
    {
        engines_[lang] = move(engine);
    }

    /* ---------------------------------------------------------- */

    void ScriptSystem::start()
    {
        // auto view = registry_.view<ScriptComponent>();
        // for (auto entity : view)
        // {
        //     auto& comp = view.get<ScriptComponent>(entity);
        //     if (!comp.isEnabled()) continue;

        //     if (auto engineIt = engines_.find(comp.getLanguage());
        //         engineIt != engines_.end() && engineIt->second)
        //     {
        //         engineIt->second->runStart(entity, comp);
        //     }
        // }
    }

    /* ---------------------------------------------------------- */

    void ScriptSystem::update(float deltaTime)
    {
        // auto view = registry_.view<ScriptComponent>();
        // for (auto entity : view)
        // {
        //     auto& comp = view.get<ScriptComponent>(entity);
        //     if (!comp.isEnabled()) continue;

        //     if (auto engineIt = engines_.find(comp.getLanguage());
        //         engineIt != engines_.end() && engineIt->second)
        //     {
        //         engineIt->second->runUpdate(entity, comp, deltaTime);
        //     }
        // }
    }

    /* ---------------------------------------------------------- */

    void ScriptSystem::broadcastEvent(const string& eventName)
    {
        // auto view = registry_.view<ScriptComponent>();
        // for (auto entity : view)
        // {
        //     auto& comp = view.get<ScriptComponent>(entity);
        //     if (!comp.isEnabled()) continue;

        //     if (auto engineIt = engines_.find(comp.getLanguage());
        //         engineIt != engines_.end() && engineIt->second)
        //     {
        //         engineIt->second->runEvent(entity, comp, eventName);
        //     }
        // }
    }

} // namespace retronomicon::lib::scripting
