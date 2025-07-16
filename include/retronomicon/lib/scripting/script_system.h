#pragma once

#include <unordered_map>
#include <memory>
#include <string>

#include "retronomicon/lib/scripting/script_component.h"
#include "retronomicon/lib/scripting/script_language.h"
namespace retronomicon::lib::scripting {

    class IScriptEngine;

    /**
     * ScriptSystem
     * ------------
     * Iterates over every entity that carries a ScriptComponent
     * and dispatches lifecycle calls to the appropriate IScriptEngine
     * implementation (Lua, Python, etc.).
     */
    class ScriptSystem {
    public:
        ScriptSystem() = default;

        /** Register a language‑specific engine (call at bootstrap). */
        void registerEngine(retronomicon::lib::scripting::ScriptLanguage lang,
                            std::shared_ptr<IScriptEngine> engine);

        /** One‑shot initialization (call after scene/world load). */
        void start();

        /** Per‑frame update (fixed or variable delta). */
        void update(float deltaTime);

        /** Broadcast a named event to all active scripts. */
        void broadcastEvent(const std::string& eventName);

        /** (Optional) Provide access to ECS registry, if needed later. */
        // void setRegistry(entt::registry* registry);  // Uncomment when integrating ECS

    private:
        std::unordered_map<retronomicon::lib::scripting::ScriptLanguage,
                           std::shared_ptr<IScriptEngine>> engines_;

        // entt::registry* registry_ = nullptr; // Optional ECS registry hook
    };

} // namespace retronomicon::lib::scripting
