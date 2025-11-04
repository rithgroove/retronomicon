#include "retronomicon/component/sprite_component.h"
#include "retronomicon/entity/entity.h"
#include "retronomicon/component/transform_component.h"
#include "retronomicon/component/animation_component.h"
#include "retronomicon/graphics/i_window.h"
#include <iostream>

namespace retronomicon::component {

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
    }

    void SpriteComponent::update(float /*dt*/) {
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


        if (m_animation) {

        } else {
            int w = static_cast<int>(m_image->getWidth() * m_transform->getScaleX());
            int h = static_cast<int>(m_image->getHeight() * m_transform->getScaleY());
            int centerX = static_cast<int>(w * m_transform->getAnchorX());
            int centerY = static_cast<int>(m_image->getHeight() * m_transform->getScaleY());
            std::cout << "x : " << x << std::endl;
            std::cout << "y : " << y << std::endl;
            x-=centerX;
            y-=centerY;
            std::cout << "x after : " << x << std::endl;
            std::cout << "y after : " << y << std::endl;
            std::cout << "w : " << w << std::endl;
            std::cout << "h : " << h << std::endl;
            std::cout << "center x : " << centerX << std::endl;
            std::cout << "center y : " << centerY << std::endl;
            std::cout << "scale x : " << m_transform->getScaleX() << std::endl;
            std::cout << "scale y : " << m_transform->getScaleY() << std::endl;
        }
        renderer->render(m_texture, Vec2(float(x) ,float(y)), Vec2(m_transform->getScaleX(),m_transform->getScaleY()), 0.0f, 1.0f);
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
