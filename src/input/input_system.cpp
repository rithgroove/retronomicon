
#include <sstream>
#include <iostream>
#include "retronomicon/lib/input_system.h"
#include "retronomicon/lib/input_component.h"

/**
 * @brief This namespace is for handling input
 */
namespace retronomicon::lib::input{

    /***************************** Constructor *****************************/

    /**
     * @brief default constructor
     */
    InputSystem::InputSystem() // Temp init to avoid reference error
    {}

    /**
     * @brief default constructor
     */
    InputSystem::InputSystem(std::shared_ptr<InputState> inputState) // Temp init to avoid reference error
    {
        m_inputState = inputState;

        // If m_gameObjects should be provided externally, consider refactoring the constructor
    }

    /***************************** Destructor *****************************/

    InputSystem::~InputSystem(){
        std::cout<<"masuk input system destructor" << std::endl;
        m_inputState = nullptr;
    } //default destructor


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
        if (!m_inputState) return;

        // std::cout<<m_inputState<<std::endl;

        auto input = entity->getComponent<InputComponent>();
        if (input){
            input->updateFromState(m_inputState,dt);
        }

        for (Entity* obj : entity->getChilds()) {
            // render logic
             this->update(dt,obj);
        }

    }


}



