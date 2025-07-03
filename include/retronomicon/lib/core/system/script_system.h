#pragma once

#include <unordered_map>
#include <memory>
#include <string>

#include "retronomicon/lib/core/component/script_component.h"   // ScriptComponent & ScriptLanguage
using namespace std;
using namespace retronomicon::lib::core::component;
namespace retronomicon::lib::core::system {

    class IScriptEngine;            // forward declaration

    /**
     * ScriptSystem
     * ------------
     * Iterates over every entity that carries a ScriptComponent
     * and dispatches lifecycle calls to the appropriate IScriptEngine
     * implementation (Lua, Python, etc.).
     */
    class ScriptSystem {
        public:
            explicit ScriptSystem();

            /** Register a language‑specific engine (call at bootstrap). */
            void registerEngine(ScriptLanguage lang,
                                shared_ptr<IScriptEngine> engine);

            /** One‑shot initialization (call after scene/world load). */
            void start();

            /** Per‑frame update (fixed or variable delta). */
            void update(float deltaTime);

            /** Broadcast a named event to all active scripts. */
            void broadcastEvent(const string& eventName);

        private:
            unordered_map<ScriptLanguage, shared_ptr<IScriptEngine>> engines_;
    };

} // namespace retronomicon::lib::scripting