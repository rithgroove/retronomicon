#pragma once

#ifdef USE_LUA  // Compile only when Lua is enabled
    #include <sol/sol.hpp>
    #include "script_engine.h"
    using namespace std;
    using namespace sol;
    namespace retronomicon::lib::scripting {

        class LuaScriptEngine : public ScriptEngine {
            public:
                LuaScriptEngine();
                ~LuaScriptEngine() override;

                void initialize() override;
                void shutdown() override;

                void loadScript(const string& path) override;
                void callFunction(const string& module,
                                  const string& funcName,
                                  float dt) override;

                void registerBindings() override;   // Expose C++ API to Lua

            private:
                state m_lua;
        };

    } // namespace retronomicon::lib::scripting
#endif // USE_LUA