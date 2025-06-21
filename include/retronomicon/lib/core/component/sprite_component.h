#pragma once

#include <SDL_image.h>
#include <iostream>
#include <string>
#include "component.h"
#include "transform_component.h"
#include "retronomicon/lib/graphic/animation/sequence_manager.h"
#include "retronomicon/lib/asset/raw_image.h"

using namespace retronomicon::lib::asset;
using namespace retronomicon::lib::core;
using namespace retronomicon::lib::graphic::animation;

namespace retronomicon::lib::core::component {

    class SpriteComponent : public Component {
        public:
            SpriteComponent(RawImage* rawImage, SequenceManager* sequenceManager = nullptr);
            ~SpriteComponent();

            void start() override;
            void update(float dt) override;
            void render(SDL_Renderer* renderer) override;

            void playSequence(const std::string& name); // Optional helper
            void setSequenceManager(SequenceManager* sequenceManager);
        private:
            RawImage* m_image;
            TransformComponent* m_transform;
            SequenceManager* m_sequenceManager; // Integrated animation controller
    };

} // namespace retronomicon