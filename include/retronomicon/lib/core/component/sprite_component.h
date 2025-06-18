#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "component.h"
#include "transform_component.h"
#include "retronomicon/lib/graphic/animation/sequence_manager.h"
#include "retronomicon/lib/asset/raw_image.h"

using namespace retronomicon::lib::graphic::animation;

namespace retronomicon::lib::core::component {

    class SpriteComponent : public Component {
        public:
            SpriteComponent(const std::string& path, SDL_Renderer* renderer);
            ~SpriteComponent();

            void start() override;
            void update(float dt) override;
            void render() override;

            void playSequence(const std::string& name); // Optional helper

        private:
            SDL_Texture* texture;
            SDL_Renderer* renderer;
            TransformComponent* transform;
            SequenceManager sequenceManager; // Integrated animation controller
    };

} // namespace retronomicon