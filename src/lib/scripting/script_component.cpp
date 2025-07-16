#include "retronomicon/lib/core/component/script_component.h"

namespace retronomicon::lib::core::component {

    ScriptComponent::ScriptComponent()
        : language(ScriptLanguage::None), entryFunction("on_update"), enabled(true) {}

    ScriptComponent::ScriptComponent(string path, ScriptLanguage lang)
        : scriptPath(move(path)), language(lang), entryFunction("on_update"), enabled(true) {}

    void ScriptComponent::onStart() {
        // Optional logic
    }

    void ScriptComponent::onUpdate(float /*deltaTime*/) {
        // Optional logic
    }

    void ScriptComponent::onEvent(const string& /*eventName*/) {
        // Optional logic
    }

    string ScriptComponent::getScriptPath() const {
        return scriptPath;
    }

    ScriptLanguage ScriptComponent::getLanguage() const {
        return language;
    }

    void ScriptComponent::setEntryFunction(string func) {
        entryFunction = move(func);
    }

    const string& ScriptComponent::getEntryFunction() const {
        return entryFunction;
    }

    bool ScriptComponent::isEnabled() const {
        return enabled;
    }

    void ScriptComponent::setEnabled(bool value) {
        enabled = value;
    }

    unordered_map<string, string>& ScriptComponent::getMetadata() {
        return metadata;
    }

} // namespace retronomicon::lib::scripting