#pragma once

#ifdef USE_LUA  // Compile only when Lua is enabled
    #include <sol/sol.hpp>
    #include "script_engine.h"

    namespace retronomicon::lib::scripting {

        class LuaScriptEngine : public ScriptEngine {
            public:
                LuaScriptEngine();
                ~LuaScriptEngine() override;

                void initialize() override;
                void shutdown() override;

                void loadScript(const std::string& path) override;
                void callFunction(const std::string& module,
                                  const std::string& funcName,
                                  float dt) override;

                void registerBindings() override;   // Expose C++ API to Lua

            private:
                sol::state lua_;
                bool       initialized_{false};
        };

    } // namespace retronomicon::lib::scripting
#endif // USE_LUA