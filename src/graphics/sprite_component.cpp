#include "retronomicon/graphics/sprite_component.h"
#include "retronomicon/core/ecs/entity.h"
#include "retronomicon/core/ecs/transform_component.h"
#include "retronomicon/animation/animation_component.h"

#include <iostream>

namespace retronomicon::graphics {
    using retronomicon::core::ecs::TransformComponent;
    using retronomicon::animation::AnimationComponent;

    SpriteComponent::SpriteComponent(std::shared_ptr<asset::ImageAsset> image)
        : m_image(std::move(image)) 
    {
        if (m_image) {
            m_texture = m_image->createTexture(); // Factory method on ImageAsset
        }
    }

    void SpriteComponent::start() {
        // Cache required components
        m_transform = getOwner()->getComponent<TransformComponent>();
        if (!m_transform) {
            std::cerr << "[SpriteComponent] Missing TransformComponent on entity.\n";
        }

        m_animation = getOwner()->getComponent<AnimationComponent>();
    }

    void SpriteComponent::update(float /*dt*/) {
        // Animation state checks could go here (optional)
    }

    void SpriteComponent::render() {
        if (!m_transform || !m_texture) return;

        if (m_animation) {
            // Render current animation frame
            const auto& currentFrame = m_animation->getCurrentFrame();
            m_texture->draw(
                *m_transform,
                currentFrame.getRect()
            );
        } else {
            // Render static image
            m_texture->draw(*m_transform);
        }
    }

    void SpriteComponent::changeAsset(std::shared_ptr<asset::ImageAsset> asset) {
        m_image = std::move(asset);
        if (m_image) {
            m_texture = m_image->createTexture();
        } else {
            m_texture.reset();
        }
    }

} // namespace retronomicon::graphics
