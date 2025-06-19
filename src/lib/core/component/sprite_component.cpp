#include "retronomicon/lib/core/component/sprite_component.h"
#include "retronomicon/lib/core/game_object.h"

namespace retronomicon::lib::core::component {

    SpriteComponent::SpriteComponent(RawImage* image, SDL_Renderer* renderer,SequenceManager* sequenceManager){
        m_image = image;
        m_renderer = renderer;
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
        m_sequenceManager->update(dt);
    }

    void SpriteComponent::render() {
        std::cout << "get frame" << std::endl;
        const Frame& currentFrame = m_sequenceManager->getCurrentFrame();

        std::cout << "bikin rect" << std::endl;
        SDL_Rect dstRect;
        std::cout << "bikin rect" << std::endl;
        dstRect.x = static_cast<int>(m_transform->getX());
        std::cout << "bikin rect" << std::endl;
        dstRect.y = static_cast<int>(m_transform->getY());
        std::cout << "bikin rect" << std::endl;
        dstRect.w = static_cast<int>(currentFrame.getWidth() * m_transform->getScaleX());
        std::cout << "bikin rect" << std::endl;
        dstRect.h = static_cast<int>(currentFrame.getHeight() * m_transform->getScaleY());
        std::cout << "bikin rect" << std::endl;

        std::cout << "done bikin rect" << std::endl;

        SDL_RendererFlip flip = SDL_FLIP_NONE ;
        std::cout << "flip" << std::endl;
        SDL_Rect srcRect =  currentFrame.getRect()->generateSDLRect();
        std::cout << "bikin source rect" << std::endl;
        SDL_RenderCopyEx(m_renderer, m_image->getTexture(), &srcRect, &dstRect, 0.0, nullptr, flip);
        std::cout << "render" << std::endl;
    }

    void SpriteComponent::playSequence(const string& name) {
        m_sequenceManager->changeSequence(name);
    }
} // namespace retronomicon