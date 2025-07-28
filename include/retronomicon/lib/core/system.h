#pragma once
/**
 * @brief The namespace for core system
 */
#include <vector>
#include "entity.h"

using namespace std;
using namespace retronomicon::lib::core;
namespace retronomicon::lib::core{
    class System {
    public:
        virtual ~System() = default;

        virtual void update(float dt, Entity* objects) {}
        virtual void render(Entity* objects) {}
    };
}