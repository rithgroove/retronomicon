enum class ScriptBackend {
    Lua,
    Python
};

struct ScriptComponent {
    ScriptBackend backend;
    // std::string scriptPath;
};
