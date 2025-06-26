#include "retronomicon/lib/core/system/input_system.h"

namespace retronomicon::lib::core::system{
    InputSystem::InputSystem() // Temp init to avoid reference error
    {
        m_rawInput = new RawInput();

        inputMap = new InputMap();
        m_inputMap->bindAction(SDL_SCANCODE_SPACE, "jump");
        m_inputMap->bindAction(SDL_SCANCODE_RETURN, "interact");
        m_inputMap->bindAction(SDL_SCANCODE_ESCAPE,"quit");
        m_inputMap->bindAction(SDL_WINDOWEVENT_CLOSE,"quit");
        m_inputMap->bindAction(SDL_QUIT,"quit");


        m_inputMap->bindAxis(SDL_SCANCODE_A, "move_x", -1.0f);
        m_inputMap->bindAxis(SDL_SCANCODE_D, "move_x", 1.0f);
        m_inputMap->bindAxis(SDL_SCANCODE_W, "move_y", -1.0f);
        m_inputMap->bindAxis(SDL_SCANCODE_S, "move_y", 1.0f);

        m_inputState = m_inputState(m_rawInput,m_inputMap);

        // If m_gameObjects should be provided externally, consider refactoring the constructor
    }

    void InputSystem::update(float dt, vector<GameObject*>& objects) {

        m_rawInput->clear();

        m_rawInput->poll();

        const auto& events = m_rawInput->getEvents();
        const Uint8* keys = m_rawInput->getKeyboardState();

        m_inputMap->fill(m_inputState, m_rawInput->getKeyboardState());

        for (const auto& it : m_inputState->getActions()) {
            std::cout << it.first << ": " << (it.second ? "pressed" : "released") << endl;
        }

        for (const auto& it : m_inputState->getAxes()) {
            std::cout << it.first << ": " << it.second << endl;
        }

    }
}



