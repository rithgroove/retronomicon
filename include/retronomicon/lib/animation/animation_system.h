#pragma once
#include "retronomicon/lib/core/system.h"

namespace retronomicon::lib::animation{
    class AnimationSystem : public retronomicon::lib::core::System {
        public:
            AnimationSystem();
            void update(float dt, vector<GameObject*>& objects)  override;
    };
}