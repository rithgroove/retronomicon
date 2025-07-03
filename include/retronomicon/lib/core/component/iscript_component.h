#pragma once

#include <string>
using namespace std;
namespace retronomicon::lib::core::component {

    enum class ScriptLanguage {
        None,
        Lua,
        Python
    };

    class IScriptComponent {
        public:
            virtual ~IScriptComponent() = default;

            virtual void onStart() {}
            virtual void onUpdate(float deltaTime) {}
            virtual void onEvent(const string& eventName) {}

            virtual string getScriptPath() const = 0;
            virtual ScriptLanguage getLanguage() const = 0;
    };

} // namespace retronomicon::lib::scripting