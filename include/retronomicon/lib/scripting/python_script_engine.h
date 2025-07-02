#pragma once
#ifdef USE_PYTHON

#include <string>
#include "retronomicon/lib/scripting/script_engine.h"

namespace retronomicon::lib::scripting {

    class PythonScriptEngine : public ScriptEngine {
        public:
            PythonScriptEngine();
            ~PythonScriptEngine() override;

            void initialize() override;
            void shutdown() override;

            void loadScript(const std::string& path) override;
            void callFunction(const std::string& module, const std::string& funcName, float dt) override;

            void registerBindings() override; // Optional: for pybind11 or future extension

        private:
            bool initialized_;
    };

} // namespace retronomicon::lib::scripting
#endif // USE_PYTHON