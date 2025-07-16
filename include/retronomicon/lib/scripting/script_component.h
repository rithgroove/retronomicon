#pragma once

#include "iscript_component.h"
#include <string>
#include <unordered_map>
using namespace std;

namespace retronomicon::lib::scripting {

    class ScriptComponent : public IScriptComponent {
    public:
        ScriptComponent();
        ScriptComponent(string path, ScriptLanguage lang);

        void onStart() override;
        void onUpdate(float deltaTime) override;
        void onEvent(const string& eventName) override;

        string getScriptPath() const override;
        ScriptLanguage getLanguage() const override;

        void setEntryFunction(string func);
        const string& getEntryFunction() const;

        bool isEnabled() const;
        void setEnabled(bool value);

        unordered_map<string, string>& getMetadata();

    private:
        string scriptPath;
        ScriptLanguage language;
        string entryFunction;
        unordered_map<string, string> metadata;
        bool enabled;
    };

} // namespace retronomicon::lib::scripting
