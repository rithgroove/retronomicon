#include "retronomicon/lib/graphic/sprite_component.h"
#include "retronomicon/lib/graphic/internal/sdl_utils.h"
#include "retronomicon/lib/core/transform_component.h"
#include "retronomicon/lib/animation/animation_component.h"
#include "retronomicon/lib/core/entity.h"
#include <iostream>

namespace retronomicon::lib::graphic {
    using  retronomicon::lib::graphic::internal::toSDLRect;
    SpriteComponent::SpriteComponent(asset::ImageAsset* image)
        : m_image(image) {}

    void SpriteComponent::start() {
        m_transform = getOwner()->getComponent<core::TransformComponent>();
        if (!m_transform) {
            std::cerr << "[SpriteComponent] Missing TransformComponent on entity.\n";
        }

        m_animation = getOwner()->getComponent<animation::AnimationComponent>();
    }

    void SpriteComponent::update(float /*dt*/) {
        // Possibly trigger animation state changes here
    }

    void SpriteComponent::render(SDL_Renderer* renderer) {
        if (!m_transform || !m_image || !renderer) return;

        SDL_Rect dstRect;
        dstRect.x = static_cast<int>(m_transform->getX());
        dstRect.y = static_cast<int>(m_transform->getY());

        SDL_RendererFlip flip = SDL_FLIP_NONE;

        SDL_Point center = {
            static_cast<int>(dstRect.w * m_transform->getAnchorX()),
            static_cast<int>(dstRect.h * m_transform->getAnchorY())
        };

        if (m_animation) {
            const auto& currentFrame = m_animation->getCurrentFrame();
            dstRect.w = static_cast<int>(currentFrame.getWidth() * m_transform->getScaleX());
            dstRect.h = static_cast<int>(currentFrame.getHeight() * m_transform->getScaleY());

            SDL_Rect srcRect = toSDLRect(currentFrame.getRect());

            SDL_RenderCopyEx(
                renderer,
                m_image->getTexture(),
                &srcRect,
                &dstRect,
                m_transform->getRotation(),
                &center,
                flip
            );

        } else {
            dstRect.w = static_cast<int>(m_image->getWidth() * m_transform->getScaleX());
            dstRect.h = static_cast<int>(m_image->getHeight() * m_transform->getScaleY());

            SDL_RenderCopyEx(
                renderer,
                m_image->getTexture(),
                nullptr,
                &dstRect,
                m_transform->getRotation(),
                &center,
                flip
            );
        }
    }

} // namespace retronomicon::lib::graphic
