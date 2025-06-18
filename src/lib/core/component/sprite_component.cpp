#include "retronomicon/lib/core/component/sprite_component.h"

namespace retronomicon::lib::core::component {

    SpriteComponent::SpriteComponent(RawImage, SDL_Renderer* renderer)
        : texture(nullptr),
          renderer(renderer),
          transform(nullptr)
    {
        SDL_Surface* surface = IMG_Load(path.c_str());
        if (!surface) {
            std::cerr << "Failed to load image: " << path << " - " << IMG_GetError() << std::endl;
            return;
        }

        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        if (!texture) {
            std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
        }
    }

    SpriteComponent::~SpriteComponent() {
        if (texture) {
            SDL_DestroyTexture(texture);
            texture = nullptr;
        }
    }

    void SpriteComponent::start() {
        transform = getOwner()->getComponent<TransformComponent>();
        if (!transform) {
            std::cerr << "SpriteComponent requires TransformComponent\n";
        }
    }

    void SpriteComponent::update(float dt) {
        sequenceManager.update(dt);
    }

    void SpriteComponent::render() {
        if (!texture || !transform) return;

        const Frame& currentFrame = sequenceManager.getCurrentFrame();
        const SDL_Rect& srcRect = currentFrame.getSrcRect();

        SDL_Rect dstRect;
        dstRect.x = static_cast<int>(transform->getX());
        dstRect.y = static_cast<int>(transform->getY());
        dstRect.w = static_cast<int>(currentFrame.getWidth() * transform->getScaleX());
        dstRect.h = static_cast<int>(currentFrame.getHeight() * transform->getScaleY());

        SDL_RenderCopyEx(renderer, texture, &srcRect, &dstRect,
                         transform->getRotation(), nullptr, SDL_FLIP_NONE);
    }

    void SpriteComponent::playSequence(const string& name) {
        sequenceManager.changeSequence(name);
    }
} // namespace retronomicon