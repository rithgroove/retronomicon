#ifdef USE_LUA  // Compile only when Lua is enabled

#include "retronomicon/lib/scripting/lua_script_engine.h"
#include <iostream>

namespace retronomicon::lib::scripting{

    LuaScriptEngine::LuaScriptEngine() = default;

    LuaScriptEngine::~LuaScriptEngine() {
        shutdown();
    }

    void LuaScriptEngine::initialize() {
        if (m_initialized) return;

        // Open standard Lua libraries
        m_lua.open_libraries(sol::lib::base,
                            sol::lib::math,
                            sol::lib::table,
                            sol::lib::string);

        registerBindings();
        m_initialized = true;
        cout << "[LuaScriptEngine] Initialized\n";
    }

    void LuaScriptEngine::shutdown() {
        if (!m_initialized) return;
        // sol::state cleans itself up automatically on destruction
        m_initialized = false;
        cout << "[LuaScriptEngine] Shutdown\n";
    }

    void LuaScriptEngine::loadScript(const string& path) {
        if (!m_initialized) initialize();

        try {
            m_lua.script_file(path);
            cout << "[LuaScriptEngine] Loaded: " << path << '\n';
        } catch (const sol::error& err) {
            cerr << "[LuaScriptEngine] Lua error: " << err.what() << '\n';
        }
    }

    void LuaScriptEngine::callFunction(const string& module,
                                       const string& funcName,
                                       float dt) {
        if (!m_initialized) return;

        sol::table mod = m_lua[module];
        if (!mod.valid()) {
            cerr << "[LuaScriptEngine] Module not found: " << module << '\n';
            return;
        }

        sol::function func = mod[funcName];
        if (!func.valid()) {
            cerr << "[LuaScriptEngine] Function not found: " << funcName << '\n';
            return;
        }

        try {
            func(dt);                                    // call Lua fn(dt)
        } catch (const sol::error& err) {
            cerr << "[LuaScriptEngine] Lua error: " << err.what() << '\n';
        }
    }

    void LuaScriptEngine::registerBindings() {
        // Example: expose a simple log function and a 2‑D vector
        m_lua.set_function("log", [](const string& msg) {
            cout << "[Lua] " << msg << '\n';
        });

        // struct Vector2 { float x = 0, y = 0; };
        // m_lua.new_usertype<Vector2>("Vector2",
        //     sol::constructors<Vector2(), Vector2(float, float)>(),
        //     "x", &Vector2::x,
        //     "y", &Vector2::y
        // );
    }

} // namespace retronomicon::lib::scripting
#endif // USE_LUA