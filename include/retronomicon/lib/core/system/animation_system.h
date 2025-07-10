#pragma once
#include "retronomicon/lib/core/system.h"

using namespace retronomicon::lib::core;
namespace retronomicon::lib::core::system{
    class AnimationSystem : public System {
        public:
            AnimationSystem();
            void update(float dt, vector<GameObject*>& objects)  override;
    };
}