#include "retronomicon/component/transform_component.h"
#include <iostream>
#include <memory>
namespace retronomicon::component{

    TransformComponent::TransformComponent()
        : m_x(0), m_y(0), m_rotation(0), m_scaleX(1.0f), m_scaleY(1.0f) {
        m_anchorX = 0.5;
        m_anchorY = 0.5;
    }

    TransformComponent::TransformComponent(float x, float y, float rotation, float scaleX, float scaleY)
        : m_x(x), m_y(y), m_rotation(rotation), m_scaleX(scaleX), m_scaleY(scaleY) {
        m_anchorX = 0.5;
        m_anchorY = 0.5;
    }

    void TransformComponent::setPosition(float newX, float newY) {
        m_x = newX;
        m_y = newY;
        m_anchorX = 0.5;
        m_anchorY = 0.5;
    }

    void TransformComponent::setAnchor(float anchorX,float anchorY){
        m_anchorX = anchorX;
        m_anchorY = anchorY;
    }

    void TransformComponent::setRotation(float angle) {
        m_rotation = angle;
    }

    void TransformComponent::setScale(float sX, float sY) {
        m_scaleX = sX;
        m_scaleY = sY;
    }

    float TransformComponent::getX() const { return m_x; }
    float TransformComponent::getY() const { return m_y; }

    Vec2 TransformComponent::getPosition() const{
        return Vec2{m_x,m_y};
    }

    Vec2 TransformComponent::getRenderPosition() const {
        // Start with our local position
        Vec2 worldPos = this->getPosition();
        return worldPos;
        // std::shared_ptr<Entity>  owner = this->getOwner();
        // auto renderable = owner->getMainRenderableComponent();
        // if (renderable){
        //     auto size= renderable->getSize();
        //     worldPos.x -= size.getWidth()*this->m_anchorX;
        //     worldPos.y -= size.getHeight()*this->m_anchorY;
        // }
        
        // // get owner
        // std::shared_ptr<Entity> parent = this->getOwner()->getParent();

        // /*
        // * since there is posibilities that owner doesnt not have transform,
        // * we traverse to find owner that have transform component (
        // * (or stop when we find the owner that doesn't have parent)
        // */ 
        // while (parent->hasParent()) {
        //     // check if it has transform component
        //     if (parent->hasComponent<TransformComponent>()) {
        //         // if have, break from loop
        //         break; 
        //     }else{
        //         // if not set owner as their parent
        //         parent = parent->getParent();
        //     }
        // }

        // // check if the owner doesn't have transform component
        // // this means we're at the scene level
        // if (parent->hasComponent<TransformComponent>()){
        //     // if we have, gather it, and call recursively
        //     const auto& parentTransform = parent->getComponent<TransformComponent>();
        //     worldPos += parentTransform->getRenderPosition();            
        // }

        // return worldPos;
    }
    float TransformComponent::getRotation() const { return m_rotation; }
    float TransformComponent::getScaleX() const { return m_scaleX; }
    float TransformComponent::getScaleY() const { return m_scaleY; }
    float TransformComponent::getAnchorX() const { return m_anchorX; }
    float TransformComponent::getAnchorY() const { return m_anchorY; }

} // namespace retronomicon
