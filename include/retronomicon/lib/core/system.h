#pragma once
/**
 * @brief The namespace for core system
 */
#include <vector>
#include "game_object.h"

using namespace std;
using namespace retronomicon::lib::core;
namespace retronomicon::lib::core{
    class System {
    public:
        virtual ~System() = default;

        virtual void update(float dt, vector<GameObject*>& objects) {}
        virtual void render(vector<GameObject*>& objects) {}
    };
}