#include "retronomicon/lib/core/component/sprite_component.h"
#include "retronomicon/lib/core/game_object.h"

namespace retronomicon::lib::core::component {

    SpriteComponent::SpriteComponent(RawImage* image, SequenceManager* sequenceManager){
        m_image = image;
        m_sequenceManager = sequenceManager;
    }

    SpriteComponent::~SpriteComponent() {
    }

    void SpriteComponent::setSequenceManager(SequenceManager *sequenceManager){
        m_sequenceManager = sequenceManager;
    }

    void SpriteComponent::start() {
        m_transform = getOwner()->getComponent<TransformComponent>();
        if (!m_transform) {
            std::cerr << "SpriteComponent requires TransformComponent\n";
        }
    }

    void SpriteComponent::update(float dt) {
        if (m_sequenceManager){
            m_sequenceManager->update(dt);
        }
    }

    void SpriteComponent::render(SDL_Renderer* renderer) {
        SDL_Rect dstRect;
        dstRect.x = static_cast<int>(m_transform->getX());
        dstRect.y = static_cast<int>(m_transform->getY());
        SDL_RendererFlip flip = SDL_FLIP_NONE ;

        if (m_sequenceManager){
            const Frame& currentFrame = m_sequenceManager->getCurrentFrame();
            dstRect.w = static_cast<int>(currentFrame.getWidth() * m_transform->getScaleX());
            dstRect.h = static_cast<int>(currentFrame.getHeight() * m_transform->getScaleY());

            SDL_Rect srcRect=  currentFrame.getRect()->generateSDLRect();

            SDL_Point center;
            center.x = static_cast<int>(dstRect.w * m_transform->getAnchorX());
            center.y = static_cast<int>(dstRect.h * m_transform->getAnchorY());

            SDL_RenderCopyEx(renderer, m_image->getTexture(), &srcRect, &dstRect, m_transform->getRotation(), &center, flip);            

        }else{
            dstRect.w = static_cast<int>(m_image->getWidth() * m_transform->getScaleX());
            dstRect.h = static_cast<int>(m_image->getHeight() * m_transform->getScaleY());

            SDL_Point center;
            center.x = static_cast<int>(dstRect.w * m_transform->getAnchorX());
            center.y = static_cast<int>(dstRect.h * m_transform->getAnchorY());

            SDL_RenderCopyEx(renderer, m_image->getTexture(), nullptr, &dstRect, m_transform->getRotation(), &center, flip);            
        }



    }

    void SpriteComponent::playSequence(const string& name) {
        m_sequenceManager->changeSequence(name);
    }
} // namespace retronomicon