#ifdef USE_LUA

#include "retronomicon/lib/scripting/lua_script_engine.h"
#include <iostream>

namespace retronomicon::lib::scripting {

    LuaScriptEngine::LuaScriptEngine() = default;

    LuaScriptEngine::~LuaScriptEngine() {
        shutdown();
    }

    void LuaScriptEngine::initialize() {
        if (m_initialized) return;

        m_lua.open_libraries(
            sol::lib::base,
            sol::lib::math,
            sol::lib::table,
            sol::lib::string
        );

        registerBindings();
        m_initialized = true;

        std::cout << "[LuaScriptEngine] Initialized\n";
    }

    void LuaScriptEngine::shutdown() {
        if (!m_initialized) return;

        // Cleanup handled by sol::state destructor
        m_initialized = false;
        std::cout << "[LuaScriptEngine] Shutdown\n";
    }

    void LuaScriptEngine::loadScript(const std::string& path) {
        if (!m_initialized) initialize();

        try {
            m_lua.script_file(path);
            std::cout << "[LuaScriptEngine] Loaded: " << path << '\n';
        } catch (const sol::error& err) {
            std::cerr << "[LuaScriptEngine] Lua error: " << err.what() << '\n';
        }
    }

    void LuaScriptEngine::callFunction(const std::string& module,
                                       const std::string& funcName,
                                       float dt) {
        if (!m_initialized) return;

        sol::table mod = m_lua[module];
        if (!mod.valid()) {
            std::cerr << "[LuaScriptEngine] Module not found: " << module << '\n';
            return;
        }

        sol::function func = mod[funcName];
        if (!func.valid()) {
            std::cerr << "[LuaScriptEngine] Function not found: " << funcName << '\n';
            return;
        }

        try {
            func(dt);
        } catch (const sol::error& err) {
            std::cerr << "[LuaScriptEngine] Lua error: " << err.what() << '\n';
        }
    }

    void LuaScriptEngine::registerBindings() {
        m_lua.set_function("log", [](const std::string& msg) {
            std::cout << "[Lua] " << msg << '\n';
        });

        // Future example:
        // m_lua.new_usertype<Vector2>("Vector2",
        //     sol::constructors<Vector2(), Vector2(float, float)>(),
        //     "x", &Vector2::x,
        //     "y", &Vector2::y
        // );
    }

    ScriptLanguage LuaScriptEngine::getLanguage() const {
        return ScriptLanguage::Lua;
    }

} // namespace retronomicon::lib::scripting

#endif // USE_LUA
