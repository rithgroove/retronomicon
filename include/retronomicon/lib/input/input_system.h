#pragma once

#include <vector>
#include "retronomicon/lib/input/input_state.h"
#include "retronomicon/lib/core/game_object.h"
#include "retronomicon/lib/core/system.h"

namespace retronomicon::lib::input {

    class InputSystem : public System {
        public:
            InputSystem();
            void update(float dt, vector<retronomicon::lib::core::GameObject*>& objects)  override;
            bool getInputStateForKey(const string& key);
        private:
            InputState* m_inputState;
    };

} // namespace retronomicon::lib::core::system