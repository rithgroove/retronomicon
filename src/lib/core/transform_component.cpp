#include "retronomicon/lib/core/transform_component.h"
#include "retronomicon/lib/core/entity.h"
#include "retronomicon/lib/core/renderable.h"
#include <iostream>
namespace retronomicon::lib::core{
    using retronomicon::lib::core::Entity;
    using retronomicon::lib::core::Renderable;
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

        Entity* owner = this->getOwner();
        auto renderable = owner->getMainRenderableComponent();
        if (renderable){
            auto size= renderable->getSize();
            worldPos.x -= size.getWidth()*this->m_anchorX;
            worldPos.y -= size.getHeight()*this->m_anchorY;
        }
        
        // get owner
        Entity* parent = this->getOwner()->getParent();

        /*
        * since there is posibilities that owner doesnt not have transform,
        * we traverse to find owner that have transform component (
        * (or stop when we find the owner that doesn't have parent)
        */ 
        while (parent->hasParent()) {
            // check if it has transform component
            if (parent->hasComponent<TransformComponent>()) {
                // if have, break from loop
                break; 
            }else{
                // if not set owner as their parent
                parent = parent->getParent();
            }
        }

        // check if the owner doesn't have transform component
        // this means we're at the scene level
        if (parent->hasComponent<TransformComponent>()){
            // if we have, gather it, and call recursively
            const auto& parentTransform = parent->getComponent<TransformComponent>();
            worldPos += parentTransform->getRenderPosition();            
        }

        return worldPos;
    }
    float TransformComponent::getRotation() const { return rotation; }
    float TransformComponent::getScaleX() const { return scaleX; }
    float TransformComponent::getScaleY() const { return scaleY; }
    float TransformComponent::getAnchorX() const { return m_anchorX; }
    float TransformComponent::getAnchorY() const { return m_anchorY; }

} // namespace retronomicon
