#include "retronomicon/lib/input/input_map.h"
#include <sstream>

/**
 * @brief This namespace is for handling input
 */
namespace retronomicon::lib::input {
    /***************************** Destructor *****************************/

    /**
     * @brief default constructor
     */
    InputMap::InputMap(){}

    /***************************** Destructor *****************************/

    // InputMap::~InputMap();

    /***************************** To String *****************************/
    
    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string InputMap::to_string() const{
        std::ostringstream oss;
        oss << "[Input Map]\n";
        return oss.str();
    }

    /***************************** Main methods *****************************/

    /**
     * @brief a method to bind action to SDL key
     * 
     * @param key SDL_Scancode the SDL_Scancode key
     * @param actionName the action name (like jump/ attack/ etc)
     */
    void InputMap::bindAction(SDL_Scancode key, const std::string& actionName) {
        m_actionBindings[key] = actionName;
    }

    /**
     * @brief method to get all action Bindings
     * 
     * @return unordered map of axis bindings
     */
    void InputMap::bindAxis(SDL_Scancode key, const std::string& axisName, float weight) {
        m_axisBindings[axisName].emplace_back(key, weight);
    }

} // namespace retronomicon::lib::input
