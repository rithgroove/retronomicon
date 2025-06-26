#pragma once

#include <vector>
#include "system.h"
#include "retronomicon/lib/core/component/input_component.h"
#include "retronomicon/lib/input/input_state.h"
#include "retronomicon/lib/core/game_object.h"

using namespace std;
using namespace retronomicon::lib::core::component;
using namespace retronomicon::lib::core;
using namespace retronomicon::lib::input;

namespace retronomicon::lib::core::system {

class InputSystem : public System {
    public:
        InputSystem(InputState* state);
        void update(float dt, vector<GameObject*>& objects)  override;

    private:
        InputState* m_inputState;
        RawInput *m_rawInput;
        InputMap *m_inputMap;
    };

} // namespace retronomicon::lib::core::system