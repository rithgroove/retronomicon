#pragma once

#include <vector>
#include "system.h"
#include "retronomicon/lib/core/component/input_component.h"
#include "retronomicon/lib/input/input_state.h"
#include "retronomicon/lib/input/input_map.h"
#include "retronomicon/lib/input/raw_input.h"
#include "retronomicon/lib/core/game_object.h"

using namespace std;
using namespace retronomicon::lib::core::component;
using namespace retronomicon::lib::core;
using namespace retronomicon::lib::input;

namespace retronomicon::lib::core::system {

    class InputSystem : public System {
        public:
            InputSystem();
            void update(float dt, vector<GameObject*>& objects)  override;
            bool getInputStateForKey(const string& key);
        private:
            InputState* m_inputState;
    };

} // namespace retronomicon::lib::core::system