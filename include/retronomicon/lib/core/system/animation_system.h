#include "system.h"

namespace retronomicon::lib::core::system{
    class AnimationSystem : public System {
        public:
            AnimationSystem();
            void update(float dt, vector<GameObject*>& objects)  override;
    };
}