#include "retronomicon/lib/core/transform_component.h"
#include "retronomicon/lib/core/entity.h"
#include <iostream>
namespace retronomicon::lib::core{
    using retronomicon::lib::core::Entity;
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

    Vec2 TransformComponent::getPosition() const{
        return Vec2{x,y};
    }

    Vec2 TransformComponent::getRenderPosition() const {
        // Start with our local position

        Vec2 worldPos = this->getPosition();

        // Walk up the parent chain
        Entity* current = this->getOwner();
        while (current->hasParent()) {
            current = current->getParent();
            if (current->hasComponent<TransformComponent>()) {
                const auto& parentTransform = current->getComponent<TransformComponent>();
                worldPos += parentTransform->getPosition(); // could be parentTransform.getRenderPosition() if recursive
            }
        }

        return worldPos;
    }
    float TransformComponent::getRotation() const { return rotation; }
    float TransformComponent::getScaleX() const { return scaleX; }
    float TransformComponent::getScaleY() const { return scaleY; }
    float TransformComponent::getAnchorX() const { return m_anchorX; }
    float TransformComponent::getAnchorY() const { return m_anchorY; }

} // namespace retronomicon
