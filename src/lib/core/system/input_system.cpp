#include "retronomicon/lib/core/system/input_system.h"

namespace retronomicon::lib::core::system{
    InputSystem::InputSystem() // Temp init to avoid reference error
    {
        RawInput* rawInput = new RawInput();

        InputMap* inputMap = new InputMap();
        inputMap->bindAction(SDL_SCANCODE_SPACE, "jump");
        inputMap->bindAction(SDL_SCANCODE_RETURN, "interact");
        inputMap->bindAction(SDL_SCANCODE_ESCAPE,"quit");
        inputMap->bindAction(SDL_WINDOWEVENT_CLOSE,"quit");
        inputMap->bindAction(SDL_QUIT,"quit");


        inputMap->bindAxis(SDL_SCANCODE_A, "move_x", -1.0f);
        inputMap->bindAxis(SDL_SCANCODE_D, "move_x", 1.0f);
        inputMap->bindAxis(SDL_SCANCODE_W, "move_y", -1.0f);
        inputMap->bindAxis(SDL_SCANCODE_S, "move_y", 1.0f);

        m_inputState = m_inputState(rawInput,inputMap);

        // If m_gameObjects should be provided externally, consider refactoring the constructor
    }

    void InputSystem::update(float dt, vector<GameObject*>& objects) {
        m_inputState->updateFromSDL();
        for (auto& obj :objects){
            auto input = obj->getComponent<InputComponent>();
            if (!input) continue;
            input->update(dt);
        }


    }
}



