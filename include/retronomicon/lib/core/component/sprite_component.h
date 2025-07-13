#pragma once

#include <SDL_image.h>
#include <iostream>
#include <string>

#include "transform_component.h"
#include "retronomicon/lib/animation/animation_component.h"
#include "retronomicon/lib/asset/image_asset.h"
#include "retronomicon/lib/core/component.h"
#include "retronomicon/lib/core/renderable.h"

using namespace retronomicon::lib::core;
using namespace retronomicon::lib::asset;
using namespace retronomicon::lib::core;
using namespace retronomicon::lib::animation;

namespace retronomicon::lib::core::component {

    class SpriteComponent : public Component, public Renderable {
        public:
            SpriteComponent(ImageAsset* imageAsset);
            ~SpriteComponent();

            void start() override;
            void update(float dt) override;
            void render(SDL_Renderer* renderer) override;

        private:
            ImageAsset* m_image;
            TransformComponent* m_transform;
            AnimationComponent* m_animation;
    };

} // namespace retronomicon