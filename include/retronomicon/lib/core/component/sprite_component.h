#pragma once

#include <SDL.h>
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
            SpriteComponent(RawImage* rawImage, SDL_Renderer* renderer,SequenceManager* sequenceManager = nullptr);
            ~SpriteComponent();

            void start() override;
            void update(float dt) override;
            void render() override;

            void playSequence(const std::string& name); // Optional helper
            void setSequenceManager(SequenceManager* sequenceManager);
        private:
            RawImage* m_image;
            SDL_Renderer* m_renderer;
            TransformComponent* m_transform;
            SequenceManager* m_sequenceManager; // Integrated animation controller
    };

} // namespace retronomicon