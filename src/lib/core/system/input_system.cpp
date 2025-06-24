#include "retronomicon/lib/core/system/input_system.h"

namespace retronomicon::lib::core::system{
    InputSystem::InputSystem(InputState* state) // Temp init to avoid reference error
    {
        m_inputState = state;
        // If m_gameObjects should be provided externally, consider refactoring the constructor
    }

    void InputSystem::update(float dt, vector<GameObject*>& objects) {
        for (GameObject* obj : objects) {
            obj->update(dt);


            InputComponent *input = obj->getComponent<InputComponent>();
            if (input != nullptr){
                input->clear();

                for (const auto& it : m_inputState->getActions()) {
                    input->setAction(it.first, it.second);
                }

                for (const auto& it : m_inputState->getAxes()) {
                    input->setAxis(it.first, it.second);
                }                
            }

        }
    }
}



