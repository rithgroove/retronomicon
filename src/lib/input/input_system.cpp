
#include <sstream>
#include <iostream>
#include "retronomicon/lib/input/input_system.h"
#include "retronomicon/lib/input/input_component.h"

/**
 * @brief This namespace is for handling input
 */
namespace retronomicon::lib::input{

    /***************************** Constructor *****************************/

    /**
     * @brief default constructor
     */
    InputSystem::InputSystem() // Temp init to avoid reference error
    {
        RawInput* rawInput = new RawInput();

        InputMap* inputMap = new InputMap();
        inputMap->bindAction(SDL_SCANCODE_SPACE, "jump");
        inputMap->bindAction(SDL_SCANCODE_RETURN, "interact");
        inputMap->bindAction(SDL_SCANCODE_ESCAPE,"quit");
        // inputMap->bindAction(SDL_WINDOWEVENT_CLOSE,"quit");
        // inputMap->bindAction(SDL_QUIT,"quit");


        inputMap->bindAxis(SDL_SCANCODE_A, "move_x", -1.0f);
        inputMap->bindAxis(SDL_SCANCODE_D, "move_x", 1.0f);
        inputMap->bindAxis(SDL_SCANCODE_W, "move_y", -1.0f);
        inputMap->bindAxis(SDL_SCANCODE_S, "move_y", 1.0f);

        m_inputState = new InputState(rawInput,inputMap);

        // If m_gameObjects should be provided externally, consider refactoring the constructor
    }

    /**
     * @brief default constructor
     */
    InputSystem::InputSystem(InputMap* inputMap) // Temp init to avoid reference error
    {
        RawInput* rawInput = new RawInput();

        m_inputState = new InputState(rawInput,inputMap);

        // If m_gameObjects should be provided externally, consider refactoring the constructor
    }

    /***************************** Destructor *****************************/

    // InputSystem::~InputSystem(); //default destructor


    /***************************** To String *****************************/
    
    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string InputSystem::to_string() const{
        std::ostringstream oss;
        oss << "[Input System]\n";
        return oss.str();
    }

    /***************************** Override Method *****************************/

    /**
     * @brief method to update all component
     * 
     * @param dt time interval since last update
     * @param objects the game objects (might change to Entity Later)
     */
    void InputSystem::update(float dt, Entity* entity) {
        if (!m_isUpdating){
            // so this line of code triggered once
            m_inputState->updateFromSDL();
            m_isUpdating = true;
        }

        // std::cout<<m_inputState<<std::endl;

        auto input = entity->getComponent<InputComponent>();
        if (input){
            std::cout<<"ketemu input component" <<std::endl;
            input->updateFromState(m_inputState,dt);
        }

        for (Entity* obj : entity->getChilds()) {
            // render logic
             this->update(dt,obj);
        }

        m_isUpdating = false;
    }


}



