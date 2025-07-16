#pragma once
#ifdef USE_PYTHON

#include <string>
#include "retronomicon/lib/scripting/iscript_engine.h"
#include "retronomicon/lib/scripting/script_language.h"

namespace retronomicon::lib::scripting {

    class PythonScriptEngine : public IScriptEngine {
    public:
        PythonScriptEngine();
        ~PythonScriptEngine() override;

        void initialize() override;
        void shutdown() override;

        void loadScript(const std::string& path) override;
        void callFunction(const std::string& module,
                          const std::string& funcName,
                          float dt) override;

        void registerBindings() override;
        ScriptLanguage getLanguage() const override;
    };

} // namespace retronomicon::lib::scripting
#endif // USE_PYTHON
