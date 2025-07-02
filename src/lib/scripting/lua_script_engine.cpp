#ifdef USE_LUA  // Compile only when Lua is enabled

#include "retronomicon/lib/scripting/lua_script_engine.h"
#include <iostream>
// #include "retronomicon/lib/math/point.h"
namespace retronomicon::lib::scripting{   // convenient alias
    LuaScriptEngine::LuaScriptEngine() = default;

    LuaScriptEngine::~LuaScriptEngine() {
        shutdown();
    }

    void LuaScriptEngine::initialize() {
        if (initialized_) return;

        // Open standard Lua libraries
        lua_.open_libraries(sol::lib::base,
                            sol::lib::math,
                            sol::lib::table,
                            sol::lib::string);

        registerBindings();
        initialized_ = true;
        std::cout << "[LuaScriptEngine] Initialized\n";
    }

    void LuaScriptEngine::shutdown() {
        if (!initialized_) return;
        // sol::state cleans itself up automatically on destruction
        initialized_ = false;
        std::cout << "[LuaScriptEngine] Shutdown\n";
    }

    void LuaScriptEngine::loadScript(const std::string& path) {
        if (!initialized_) initialize();

        try {
            lua_.script_file(path);
            std::cout << "[LuaScriptEngine] Loaded: " << path << '\n';
        } catch (const sol::error& err) {
            std::cerr << "[LuaScriptEngine] Lua error: " << err.what() << '\n';
        }
    }

    void LuaScriptEngine::callFunction(const std::string& module,
                                       const std::string& funcName,
                                       float dt) {
        if (!initialized_) return;

        sol::table mod = lua_[module];
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
            func(dt);                                    // call Lua fn(dt)
        } catch (const sol::error& err) {
            std::cerr << "[LuaScriptEngine] Lua error: " << err.what() << '\n';
        }
    }

    void LuaScriptEngine::registerBindings() {
        // Example: expose a simple log function and a 2‑D vector
        lua_.set_function("log", [](const std::string& msg) {
            std::cout << "[Lua] " << msg << '\n';
        });
        
        // struct Vector2 { float x = 0, y = 0; };
        // lua_.new_usertype<Vector2>("Vector2",
        //     sol::constructors<Vector2(), Vector2(float, float)>(),
        //     "x", &Vector2::x,
        //     "y", &Vector2::y
        // );
    }

} // namespace retronomicon::lib::scripting
#endif // USE_LUA