#pragma once

#include <string>
#include "script_language.h"
namespace retronomicon::lib::scripting {

    class IScriptComponent {
        public:
            virtual ~IScriptComponent() = default;

            virtual void onStart() {}
            virtual void onUpdate(float deltaTime) {}
            virtual void onEvent(const std::string& eventName) {}

            virtual string getScriptPath() const = 0;
            virtual ScriptLanguage getLanguage() const = 0;
    };

} // namespace retronomicon::lib::scripting