#pragma once

#include <string>
#include "retronomicon/lib/scripting/script_language.h" // if ScriptLanguage is separated

namespace retronomicon::lib::scripting {

    class IScriptEngine {
    public:
        virtual ~IScriptEngine() = default;

        /// Initialize the interpreter (e.g., Lua or Python)
        virtual void initialize() = 0;

        /// Load and execute a script file
        virtual void loadScript(const std::string& path) = 0;

        /// Call a function inside a loaded script/module
        virtual void callFunction(const std::string& module,
                                  const std::string& funcName,
                                  float dt) = 0;

        /// Optional cleanup step for interpreters like Python
        virtual void shutdown() {}

        /// Optional: expose C++ engine classes to script
        virtual void registerBindings() {}

        /// Return which language this engine supports
        virtual ScriptLanguage getLanguage() const = 0;

        /// Check whether the interpreter is initialized
        virtual bool isInitialized() const { return m_initialized; }

    protected:
        bool m_initialized = false;
    };

} // namespace retronomicon::lib::scripting
