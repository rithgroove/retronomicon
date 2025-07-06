#pragma once
#include "system.h"   // Your existing System interface

namespace retronomicon::lib::core::system {

    /**
     * Pure‑interface (abstract) physics system.
     * 
     * `update()` is fixed here so concrete systems only have to
     * implement the two core steps: integration + collision‑resolution.
     */
    class PhysicsSystem : public System
    {
    public:
        virtual ~PhysicsSystem() = default;

        // System ---------------------------------------------------------------
        void update(float dt) final override
        {
            integrate(dt);
            resolveCollisions();
        }

    protected:
        /** Advance each body’s position/velocity by dt. */
        virtual void integrate(float dt)            = 0;
        /** Detect & resolve contacts for this frame.  */
        virtual void resolveCollisions()            = 0;
    };

} // namespace retronomicon::lib::core::system
