#pragma once

#include <string>
#include "retronomicon/lib/core/component.h" // Required to inherit Component

namespace retronomicon::lib::scripting {

    enum class ScriptLanguage {
        None,
        Lua,
        Python
    };

    class IScriptComponent : public retronomicon::lib::core::Component {
    public:
        virtual ~IScriptComponent() = default;

        // Override base lifecycle
        void start() override {
            onStart();
        }

        void update(float deltaTime) override {
            onUpdate(deltaTime);
        }

        // Optional event hook
        virtual void onStart() {}
        virtual void onUpdate(float deltaTime) {}
        virtual void onEvent(const std::string& eventName) {}

        // Required by scripting system
        virtual std::string getScriptPath() const = 0;
        virtual ScriptLanguage getLanguage() const = 0;
    };

} // namespace retronomicon::lib::scripting
