#include "retronomicon/lib/core/component/transform_component.h"

namespace retronomicon::lib::core::component{

    TransformComponent::TransformComponent()
        : x(0), y(0), rotation(0), scaleX(1.0f), scaleY(1.0f) {}

    TransformComponent::TransformComponent(float x, float y, float rotation, float scaleX, float scaleY)
        : x(x), y(y), rotation(rotation), scaleX(scaleX), scaleY(scaleY) {}

    void TransformComponent::setPosition(float newX, float newY) {
        x = newX;
        y = newY;
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

} // namespace retronomicon
