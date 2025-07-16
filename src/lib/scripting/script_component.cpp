#include "retronomicon/lib/scripting/script_component.h"

namespace retronomicon::lib::scripting {

    ScriptComponent::ScriptComponent()
        : language(ScriptLanguage::None),
          entryFunction("on_update"),
          enabled(true) {}

    ScriptComponent::ScriptComponent(const std::string& path, ScriptLanguage lang)
        : scriptPath(path),
          language(lang),
          entryFunction("on_update"),
          enabled(true) {}

    void ScriptComponent::onStart() {
        // Optional script-related logic to be triggered at component start
    }

    void ScriptComponent::onUpdate(float /*deltaTime*/) {
        // Optional per-frame script logic stub
    }

    void ScriptComponent::onEvent(const std::string& /*eventName*/) {
        // Optional event dispatch hook
    }

    std::string ScriptComponent::getScriptPath() const {
        return scriptPath;
    }

    ScriptLanguage ScriptComponent::getLanguage() const {
        return language;
    }

    void ScriptComponent::setEntryFunction(const std::string& func) {
        entryFunction = func;
    }

    const std::string& ScriptComponent::getEntryFunction() const {
        return entryFunction;
    }

    bool ScriptComponent::isEnabled() const {
        return enabled;
    }

    void ScriptComponent::setEnabled(bool value) {
        enabled = value;
    }

    const std::unordered_map<std::string, std::string>& ScriptComponent::getMetadata() const {
        return metadata;
    }

    void ScriptComponent::setMetadata(const std::string& key, const std::string& value) {
        metadata[key] = value;
    }

} // namespace retronomicon::lib::scripting
