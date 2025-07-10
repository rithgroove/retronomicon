#pragma once
#include "scene.h"
#include <memory>

namespace retronomicon::lib::core {

    class Engine {
    public:
        Engine();
        ~Engine();

        void run();

        Scene& active_scene();

    private:
        bool running_ = true;
        Scene scene_;
    };

}