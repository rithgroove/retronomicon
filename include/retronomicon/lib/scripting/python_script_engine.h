#pragma once
#ifdef USE_PYTHON

#include <string>
#include "retronomicon/lib/scripting/iscript_engine.h"

using namespace std;

namespace retronomicon::lib::scripting {

    class PythonScriptEngine : public IScriptEngine {
        public:
            PythonScriptEngine();
            ~PythonScriptEngine() override;

            void initialize() override;
            void shutdown() override;

            void loadScript(const string& path) override;
            void callFunction(const string& module, const string& funcName, float dt) override;
            void registerBindings() override; // Optional: for pybind11 or future extension
    };

} // namespace retronomicon::lib::scripting
#endif // USE_PYTHON