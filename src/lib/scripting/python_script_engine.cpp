#ifdef USE_PYTHON

#include "retronomicon/lib/scripting/python_script_engine.h"
#include <Python.h>
#include <iostream>

namespace retronomicon::lib::scripting {

    PythonScriptEngine::PythonScriptEngine() = default;

    PythonScriptEngine::~PythonScriptEngine() {
        shutdown();
    }

    void PythonScriptEngine::initialize() {
        if (!m_initialized) {
            Py_Initialize();
            m_initialized = true;
            std::cout << "[PythonScriptEngine] Initialized\n";
        }
    }

    void PythonScriptEngine::shutdown() {
        if (m_initialized) {
            Py_Finalize();
            m_initialized = false;
            std::cout << "[PythonScriptEngine] Shutdown\n";
        }
    }

    void PythonScriptEngine::loadScript(const std::string& path) {
        if (!m_initialized) initialize();

        FILE* file = fopen(path.c_str(), "r");
        if (file) {
            PyRun_SimpleFile(file, path.c_str());
            fclose(file);
            std::cout << "[PythonScriptEngine] Loaded: " << path << '\n';
        } else {
            std::cerr << "[PythonScriptEngine] Failed to open: " << path << '\n';
        }
    }

    void PythonScriptEngine::callFunction(const std::string& moduleName,
                                          const std::string& funcName,
                                          float dt) {
        if (!m_initialized) return;

        PyObject* pName = PyUnicode_DecodeFSDefault(moduleName.c_str());
        PyObject* pModule = PyImport_Import(pName);
        Py_DECREF(pName);

        if (!pModule) {
            PyErr_Print();
            std::cerr << "[PythonScriptEngine] Failed to import module: " << moduleName << '\n';
            return;
        }

        PyObject* pFunc = PyObject_GetAttrString(pModule, funcName.c_str());
        if (pFunc && PyCallable_Check(pFunc)) {
            PyObject* args = PyTuple_Pack(1, PyFloat_FromDouble(dt));
            PyObject* result = PyObject_CallObject(pFunc, args);
            Py_DECREF(args);

            if (result) {
                std::cout << "[PythonScriptEngine] " << funcName << " executed\n";
                Py_DECREF(result);
            } else {
                PyErr_Print();
                std::cerr << "[PythonScriptEngine] Function call failed: " << funcName << '\n';
            }
        } else {
            PyErr_Print();
            std::cerr << "[PythonScriptEngine] Function not found or not callable: " << funcName << '\n';
        }

        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }

    void PythonScriptEngine::registerBindings() {
        // Optional: expose C++ types/functions to Python using pybind11
    }

    ScriptLanguage PythonScriptEngine::getLanguage() const {
        return ScriptLanguage::Python;
    }

} // namespace retronomicon::lib::scripting

#endif // USE_PYTHON
