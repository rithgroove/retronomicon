#include "retronomicon/lib/core/component/sprite_component.h"

namespace retronomicon::lib::core::component {

    SpriteComponent::SpriteComponent(RawImage* image, SDL_Renderer* renderer){
        m_image = image;
        m_renderer = renderer;
        m_sequenceManager = nullptr;
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
        m_sequenceManager->update(dt);
    }

    void SpriteComponent::render() {
 
        const Frame& currentFrame = m_sequenceManager->getCurrentFrame();

        SDL_Rect dstRect;
        dstRect.x = static_cast<int>(m_transform->getX());
        dstRect.y = static_cast<int>(m_transform->getY());
        dstRect.w = static_cast<int>(currentFrame.getWidth() * m_transform->getScaleX());
        dstRect.h = static_cast<int>(currentFrame.getHeight() * m_transform->getScaleY());

        SDL_RendererFlip flip = SDL_FLIP_NONE ;
        SDL_Rect srcRect =  currentFrame.getRect()->generateSDLRect();
        SDL_RenderCopyEx(m_renderer, m_image->getTexture(), &srcRect, &dstRect, 0.0, nullptr, flip)
    }

    void SpriteComponent::playSequence(const string& name) {
        m_sequenceManager->changeSequence(name);
    }
} // namespace retronomicon