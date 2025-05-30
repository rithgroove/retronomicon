#include "retronomicon/lib/graphic/renderable/sprite.h"
#include <iostream>

namespace retronomicon::lib::graphic{
    Sprite::Sprite(RawImage* image, int x, int y){
        m_texture = image.getTexture();
        m_width = image.getWidth();
        m_height = image.getHeight();
        m_x = x;
        m_y = y;
        SDL_FreeSurface(surface);
    }

    Sprite::~Sprite() {
        if (m_texture) {
            SDL_DestroyTexture(m_texture);
            m_texture = nullptr;
        }
    }

    void Sprite::render(SDL_Renderer renderer) {
        SDL_Rect dst = { m_x, m_y, m_width, m_height };
        SDL_RenderCopyEx(renderer, m_texture, nullptr, &dstRect, 0.0, nullptr, flip);
    }

    void Sprite::render(const SDL_Rect& dstRect, SDL_RendererFlip flip) {
        SDL_RenderCopyEx(m_renderer, m_texture, nullptr, &dstRect, 0.0, nullptr, flip);
    }

    int Sprite::getWidth() const {
        return m_width;
    }

    int Sprite::getHeight() const {
        return m_height;
    }

    // Move constructor
    Sprite::Sprite(Sprite&& other) noexcept {
        m_renderer = other.m_renderer;
        m_texture = other.m_texture;
        m_width = other.m_width;
        m_height = other.m_height;

        other.m_texture = nullptr;
    }

    // Move assignment
    Sprite& Sprite::operator=(Sprite&& other) noexcept {
        if (this != &other) {
            if (m_texture) {
                SDL_DestroyTexture(m_texture);
            }

            m_renderer = other.m_renderer;
            m_texture = other.m_texture;
            m_width = other.m_width;
            m_height = other.m_height;

            other.m_texture = nullptr;
        }
        return *this;
    }

}