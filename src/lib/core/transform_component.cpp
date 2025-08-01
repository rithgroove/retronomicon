#include "retronomicon/lib/core/transform_component.h"

namespace retronomicon::lib::core{

    TransformComponent::TransformComponent()
        : x(0), y(0), rotation(0), scaleX(1.0f), scaleY(1.0f) {
        m_anchorX = 0.5;
        m_anchorY = 0.5;
    }

    TransformComponent::TransformComponent(float x, float y, float rotation, float scaleX, float scaleY)
        : x(x), y(y), rotation(rotation), scaleX(scaleX), scaleY(scaleY) {
        m_anchorX = 0.5;
        m_anchorY = 0.5;
    }

    void TransformComponent::setPosition(float newX, float newY) {
        x = newX;
        y = newY;
        m_anchorX = 0.5;
        m_anchorY = 0.5;
    }

    void TransformComponent::setAnchor(float anchorX,float anchorY){
        m_anchorX = anchorX;
        m_anchorY = anchorY;
    }

    void TransformComponent::setRotation(float angle) {
        rotation = angle;
    }

    void TransformComponent::setScale(float sX, float sY) {
        scaleX = sX;
        scaleY = sY;
    }

    float TransformComponent::getX() const { return x; }
    float TransformComponent::getY() const { return y; }
    float TransformComponent::getRotation() const { return rotation; }
    float TransformComponent::getScaleX() const { return scaleX; }
    float TransformComponent::getScaleY() const { return scaleY; }
    float TransformComponent::getAnchorX() const { return m_anchorX; }
    float TransformComponent::getAnchorY() const { return m_anchorY; }

} // namespace retronomicon
