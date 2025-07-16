#pragma once

#ifdef USE_LUA

#include <sol/sol.hpp>
#include "iscript_engine.h"
#include "script_language.h" // Just in case ScriptLanguage is elsewhere

namespace retronomicon::lib::scripting {

    class LuaScriptEngine : public IScriptEngine {
    public:
        LuaScriptEngine();
        ~LuaScriptEngine() override;

        void initialize() override;
        void shutdown() override;

        void loadScript(const std::string& path) override;
        void callFunction(const std::string& module,
                          const std::string& funcName,
                          float dt) override;

        void registerBindings() override;

        ScriptLanguage getLanguage() const override;

    private:
        sol::state m_lua;
    };

} // namespace retronomicon::lib::scripting

#endif // USE_LUA
