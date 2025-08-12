#pragma once

#include <vector>
#include "retronomicon/lib/input/input_state.h"
#include "retronomicon/lib/core/entity.h"
#include "retronomicon/lib/core/system.h"

/**
 * @brief This namespace is for handling input
 */
namespace retronomicon::lib::input {
    /**
     * @brief A system that handles input. fill up input state from sdl and pass it to all input components
     */
    class InputSystem : public retronomicon::lib::core::System {
        public:
            /***************************** Constructor *****************************/

            /**
             * @brief default constructor
             */
            InputSystem();

            /**
             * @brief constructor with input map
             */
            InputSystem(InputMap* map);

            /***************************** Destructor *****************************/

            // ~InputSystem(); //default destructor

            /***************************** Operator Overload *****************************/

            /**
             * @brief overloading operator << to call to_string()
             */
            friend std::ostream& operator<<(std::ostream& os, const InputSystem& obj) {
                return os << obj.to_string();
            }
            
            /***************************** Getter *****************************/
            /**
             * @brief get state for specific key
             * might remove this method in the future.
             * 
             * @param key in string format (action)
             */
            bool getInputStateForKey(const string& key){
                return  m_inputState->isActionActive(key);
            }
        
            /***************************** To String *****************************/

            /**
             * @brief a method to help people debug this object
             * 
             * @return Brief summary of this object in string
             */
            virtual std::string to_string() const;

            /***************************** Override Method *****************************/

            /**
             * @brief method to update all component
             * 
             * @param dt time interval since last update
             * @param objects the game objects (might change to Entity Later)
             */
            void update(float dt, retronomicon::lib::core::Entity* objects)  override;
        private:
            /***************************** Attribute *****************************/
            InputState* m_inputState;
            bool m_isUpdating= false;
    };

} // namespace retronomicon::lib::core::system