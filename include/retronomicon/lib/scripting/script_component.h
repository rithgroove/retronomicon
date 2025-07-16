#pragma once

#include "iscript_component.h"
#include <string>
#include <unordered_map>

namespace retronomicon::lib::scripting {

    class ScriptComponent : public IScriptComponent {
    public:
        ScriptComponent();
        ScriptComponent(const std::string& path, ScriptLanguage lang);

        void onStart() override;
        void onUpdate(float deltaTime) override;
        void onEvent(const std::string& eventName) override;

        std::string getScriptPath() const override;
        ScriptLanguage getLanguage() const override;

        void setEntryFunction(const std::string& func);
        const std::string& getEntryFunction() const;

        bool isEnabled() const;
        void setEnabled(bool value);

        const std::unordered_map<std::string, std::string>& getMetadata() const;
        void setMetadata(const std::string& key, const std::string& value);

    private:
        std::string scriptPath;
        ScriptLanguage language;
        std::string entryFunction;
        std::unordered_map<std::string, std::string> metadata;
        bool enabled;
    };

} // namespace retronomicon::lib::scripting
