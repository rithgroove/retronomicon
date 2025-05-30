#include "retronomicon/lib/graphic/renderable/sprite.h"
#include <iostream>

namespace retronomicon::lib::graphic{
    Sprite::Sprite(RawImage* image, int x, int y){
        m_texture = image.getTexture();
        m_width = image.getWidth();
        m_height = image.getHeight();
        m_x = x;
        m_y = y;
        m_rawImage = image;
    }

    void Sprite::update(){
        return TRUE;
    }

    void Sprite::render(SDL_Renderer renderer) {
        SDL_Rect dst = { m_x, m_y, this.getWidth(), this.getHeight() };
        SDL_RenderCopyEx(renderer, m_texture, nullptr, &dstRect, 0.0, nullptr, m_flip);
        return TRUE;
    }

    int Sprite::getWidth() override {
        return (int)(m_width*m.scale);
    }

    int Sprite::getHeight() override {
        return (int)(m_height*m.scale);
    }

}