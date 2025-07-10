#pragma once

#include <SDL_image.h>
#include <iostream>
#include <string>

#include "transform_component.h"
#include "animation_component.h"
#include "retronomicon/lib/asset/raw_image.h"
#include "retronomicon/lib/core/component.h"

using namespace retronomicon::lib::core;
using namespace retronomicon::lib::asset;
using namespace retronomicon::lib::core;
using namespace retronomicon::lib::graphic::animation;

namespace retronomicon::lib::core::component {

    class SpriteComponent : public Component {
        public:
            SpriteComponent(RawImage* rawImage);
            ~SpriteComponent();

            void start() override;
            void update(float dt) override;
            void render(SDL_Renderer* renderer) override;

        private:
            RawImage* m_image;
            TransformComponent* m_transform;
            AnimationComponent* m_animation;
    };

} // namespace retronomicon