#pragma once

#include "retronomicon/lib/core/component.h"
#include "retronomicon/lib/math/vec2.h"

namespace retronomicon::lib::physics {

class PhysicsComponent : public Component {
    public:
        Vec2 velocity{0, 0};
        Vec2 acceleration{0, 0};
        float mass = 1.0f;
        bool isStatic = false;
        bool affectedByGravity = true;
        float maxFallSpeed = 1000.0f;
    };
}