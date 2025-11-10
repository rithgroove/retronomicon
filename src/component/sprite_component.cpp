#include "retronomicon/component/sprite_component.h"
#include "retronomicon/entity/entity.h"
#include "retronomicon/component/transform_component.h"
#include "retronomicon/component/animation_component.h"
#include "retronomicon/graphics/i_window.h"
#include "retronomicon/math/rect.h"
#include <iostream>

namespace retronomicon::component {
    using retronomicon::math::Rect;
    using retronomicon::math::Point;
    SpriteComponent::SpriteComponent(std::shared_ptr<asset::ImageAsset> image)
        : m_image(image) 
    {
        if (m_image) {
            // m_texture = m_image->createTexture(); // Factory method on ImageAsset
        }
    }

    void SpriteComponent::start() {
        // Cache required components
        m_transform = getOwner()->getComponent<TransformComponent>();
        if (!m_transform) {
            std::cerr << "[SpriteComponent] Missing TransformComponent on entity.\n";
        }

        m_animation = getOwner()->getComponent<AnimationComponent>();
        m_bound = getOwner()->getComponent<BoundComponent>();
    }

    void SpriteComponent::update(float /*dt*/) {
    std::cout<<"sprite component update called" <<std::endl;
        m_transform->setRotation(m_transform->getRotation()+1.0);
        // Animation state checks could go here (optional)
    }
    
    void SpriteComponent::render(std::shared_ptr<IRenderer> renderer)  { 
        std::cout<<"hallo1"<<std::endl;
        if (!m_transform || !m_texture) return;
        std::cout<<"hallo2"<<std::endl;

        float width = m_image->getWidth();
        float height = m_image->getHeight();

        int windowWidth = renderer->getWidth();
        int windowHeight = renderer->getHeight();

        Vec2 renderPosition = m_transform->getRenderPosition();
        int x = static_cast<int>(renderPosition.x);
        int y = static_cast<int>(renderPosition.y);
        float w = m_image->getWidth() * m_transform->getScaleX();
        float h = m_image->getHeight() * m_transform->getScaleY();

        if (m_bound && (w > m_bound->getWidth() || h> m_bound->getHeight())){
            float widthScale = m_bound->getWidth()/w;
            float heightScale = m_bound->getHeight()/h;
            float mainScale = std::min(widthScale,heightScale);

            w = mainScale*w;
            h = mainScale*h;
        }

        Rect source(0.0f,0.0f,width,height) ;
        Rect destination(Point(x,y),Point(m_transform->getAnchorX(),m_transform->getAnchorY()),w,h) ;
        std::cout<<destination<<std::endl;
        if (m_animation) {
            auto animationFrame  = m_animation->getCurrentFrame();
            source = animationFrame.getRect();
        }   
        renderer->renderQuad(m_texture, destination, source, m_transform->getRotation(), 1.0f);
    }

    void SpriteComponent::changeAsset(std::shared_ptr<asset::ImageAsset> asset) {
        // m_image = std::move(asset);
        // if (m_image) {
        //     m_texture = m_image->createTexture();
        // } else {
        //     m_texture.reset();
        // }
    }
    
    void SpriteComponent::generateTexture(std::shared_ptr<TextureManager> textureManager){
        m_texture= textureManager->createTexture(m_image);
    }
} // namespace retronomicon::graphics
