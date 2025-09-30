
#include <sstream>
#include <iostream>
#include "retronomicon/input/input_system.h"
#include "retronomicon/input/input_component.h"

/**
 * @brief This namespace is for handling input
 */
namespace retronomicon::input{

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
     * @param entity weak_ptr to the entity
     */
    void InputSystem::update(float dt, std::weak_ptr<Entity> entity) {
        if (auto e = entity.lock()) {
            auto comp = e->getComponent<InputComponent>();
            if (comp) {
                comp->update(dt);  // always valid now
            }

            for (auto& child : e->getChildren()) {
                update(dt, child);
            }
        }
    }
}



