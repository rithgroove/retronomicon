#include "retronomicon/component/bound_component.h"

namespace retronomicon::component {

    BoundComponent::BoundComponent()
        : m_width(0.0f), m_height(0.0f), m_offsetX(0.0f), m_offsetY(0.0f) {}

    BoundComponent::BoundComponent(float width, float height, float offsetX, float offsetY)
        : m_width(width), m_height(height), m_offsetX(offsetX), m_offsetY(offsetY) {}

    void BoundComponent::setSize(float width, float height) {
        m_width = width;
        m_height = height;
    }

    void BoundComponent::setOffset(float offsetX, float offsetY) {
        m_offsetX = offsetX;
        m_offsetY = offsetY;
    }

    float BoundComponent::getWidth() const { return m_width; }
    float BoundComponent::getHeight() const { return m_height; }
    float BoundComponent::getOffsetX() const { return m_offsetX; }
    float BoundComponent::getOffsetY() const { return m_offsetY; }

    // void BoundComponent::fitToTexture(const retronomicon::graphics::Texture& texture) {
    //     m_width = static_cast<float>(texture.getWidth());
    //     m_height = static_cast<float>(texture.getHeight());
    // }

} // namespace retronomicon::core::ecs
