#include "retronomicon/component/bound_component.h"

namespace retronomicon::component {

    BoundComponent::BoundComponent()
        : m_width(0.0f), m_height(0.0f),
          m_offsetX(0.0f), m_offsetY(0.0f),
          m_scaleMode(ScaleMode::Contain) {}

    BoundComponent::BoundComponent(float width, float height, float offsetX, float offsetY)
        : m_width(width), m_height(height),
          m_offsetX(offsetX), m_offsetY(offsetY),
          m_scaleMode(ScaleMode::Contain) {}

    void BoundComponent::setSize(float width, float height) {
        m_width = width;
        m_height = height;
    }

    void BoundComponent::setOffset(float offsetX, float offsetY) {
        m_offsetX = offsetX;
        m_offsetY = offsetY;
    }

    void BoundComponent::setScaleMode(ScaleMode mode) {
        m_scaleMode = mode;
    }

    float BoundComponent::getWidth() const { return m_width; }
    float BoundComponent::getHeight() const { return m_height; }
    float BoundComponent::getOffsetX() const { return m_offsetX; }
    float BoundComponent::getOffsetY() const { return m_offsetY; }
    ScaleMode BoundComponent::getScaleMode() const { return m_scaleMode; }

} // namespace retronomicon::component
