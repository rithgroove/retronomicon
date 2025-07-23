#pragma once

#include "retronomicon/lib/core/scene.h"

namespace retronomicon::lib::core {

    class MenuScene : public Scene {
    public:
        MenuScene();

        void init() override;
        void update(float dt) override;
        void render() override;
        void shutdown() override;

    private:
        float m_timer = 0.0f;
    };

}
