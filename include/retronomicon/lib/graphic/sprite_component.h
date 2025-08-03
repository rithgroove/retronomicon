#pragma once

#include <SDL.h>
#include <string>
#include <memory>

#include "retronomicon/lib/core/component.h"
#include "retronomicon/lib/core/renderable.h"
#include "retronomicon/lib/asset/image_asset.h"

// Forward declarations to avoid unnecessary includes
namespace retronomicon::lib::core { class TransformComponent; }
namespace retronomicon::lib::animation { class AnimationComponent; }

namespace retronomicon::lib::graphic {

    /**
     * @brief A drawable sprite that optionally supports animation.
     */
    class SpriteComponent : public core::Component, public core::Renderable {
    public:
        explicit SpriteComponent(std::shared_ptr<asset::ImageAsset> imageAsset);
        ~SpriteComponent() override = default;

        void start() override;
        void update(float dt) override;
        void render(SDL_Renderer* renderer) override;

    private:
        std::shared_ptr<asset::ImageAsset> m_image = nullptr;
        core::TransformComponent* m_transform = nullptr;
        animation::AnimationComponent* m_animation = nullptr;
    };

} // namespace retronomicon::lib::graphic
