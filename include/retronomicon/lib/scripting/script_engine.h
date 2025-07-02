#pragma once

#include <string>
using namespace std;

namespace retronomicon::lib::scripting {
    class ScriptEngine {
        public:
            virtual ~ScriptEngine() = default;

            // Initialize the interpreter (e.g., Lua or Python)
            virtual void initialize() = 0;

            // Load and execute a script file
            virtual void loadScript(const string& path) = 0;

            // Call a function inside a loaded script/module
            virtual void callFunction(const string& module, const string& funcName, float dt) = 0;

            // Optional cleanup step for interpreters like Python
            virtual void shutdown() {}

            // Optional: expose C++ engine classes to script
            virtual void registerBindings() {}

            bool isInitialized(){return m_initialized;}
            
        protected:
            bool m_initialized;
    };

} // namespace retronomicon::lib::scripting