#pragma once

#include <vector>
#include "retronomicon/lib/input/input_state.h"
#include "retronomicon/lib/core/game_object.h"
#include "retronomicon/lib/core/system.h"

namespace retronomicon::lib::input {

    class InputSystem : public retronomicon::lib::core::System {
        public:
            /***************************** Constructor *****************************/

            /**
             * @brief default constructor
             */
            InputSystem();


            /***************************** Destructor *****************************/

            // ~InputSystem(); //default destructor



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


            /***************************** Override Method *****************************/

            /**
             * @brief method to update all component
             * 
             * @param dt time interval since last update
             * @param objects the game objects (might change to Entity Later)
             */
            void update(float dt, vector<retronomicon::lib::core::GameObject*>& objects)  override;
        private:
            InputState* m_inputState;
    };

} // namespace retronomicon::lib::core::system