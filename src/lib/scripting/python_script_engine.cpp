#ifdef USE_PYTHON

#include "retronomicon/lib/scripting/python_script_engine.h"
#include <Python.h>
#include <iostream>

namespace retronomicon::lib::scripting{

    PythonScriptEngine::PythonScriptEngine() {
        m_initialized = false;
    }

    PythonScriptEngine::~PythonScriptEngine() {
        shutdown();
    }

    void PythonScriptEngine::initialize() {
        if (!m_initialized) {
            Py_Initialize();
            m_initialized = true;
            cout << "[PythonScriptEngine] Initialized\n";
        }
    }

    void PythonScriptEngine::shutdown() {
        if (m_initialized) {
            Py_Finalize();
            m_initialized = false;
            cout << "[PythonScriptEngine] Shutdown\n";
        }
    }

    void PythonScriptEngine::loadScript(const string& path) {
        if (!m_initialized) initialize();

        FILE* file = fopen(path.c_str(), "r");
        if (file) {
            PyRun_SimpleFile(file, path.c_str());
            fclose(file);
            cout << "[PythonScriptEngine] Loaded: " << path << '\n';
        } else {
            cerr << "[PythonScriptEngine] Failed to open: " << path << '\n';
        }
    }

    void PythonScriptEngine::callFunction(const string& moduleName, const string& funcName, float dt) {
        if (!m_initialized) return;

        PyObject* pName = PyUnicode_DecodeFSDefault(moduleName.c_str());
        PyObject* pModule = PyImport_Import(pName);
        Py_DECREF(pName);

        if (!pModule) {
            PyErr_Print();
            cerr << "[PythonScriptEngine] Failed to import module: " << moduleName << '\n';
            return;
        }

        PyObject* pFunc = PyObject_GetAttrString(pModule, funcName.c_str());
        if (pFunc && PyCallable_Check(pFunc)) {
            PyObject* args = PyTuple_Pack(1, PyFloat_FromDouble(dt));
            PyObject* result = PyObject_CallObject(pFunc, args);
            Py_DECREF(args);

            if (result) {
                cout << "[PythonScriptEngine] " << funcName << " returned\n";
                Py_DECREF(result);
            } else {
                PyErr_Print();
                cerr << "[PythonScriptEngine] Function call failed: " << funcName << '\n';
            }
        } else {
            PyErr_Print();
            cerr << "[PythonScriptEngine] Function not found or not callable: " << funcName << '\n';
        }

        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }

    void PythonScriptEngine::registerBindings() {
        // You can implement pybind11 bindings here if needed
    }
}

#endif // USE_PYTHON
