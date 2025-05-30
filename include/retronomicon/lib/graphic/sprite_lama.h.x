#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdexcept>
#include <iostream>


namespace retronomicon::lib::graphic{
    class Sprite {
    public:
        Sprite(SDL_Renderer* renderer, const std::string& imagePath);
        ~Sprite();

        void render(int x, int y, SDL_RendererFlip flip = SDL_FLIP_NONE);
        void render(const SDL_Rect& dstRect, SDL_RendererFlip flip = SDL_FLIP_NONE);

        int getWidth() const;
        int getHeight() const;

        // Disallow copy
        Sprite(const Sprite&) = delete;
        Sprite& operator=(const Sprite&) = delete;

        // Allow move
        Sprite(Sprite&& other) noexcept;
        Sprite& operator=(Sprite&& other) noexcept;

    private:
        SDL_Renderer* m_renderer = nullptr;
        SDL_Texture* m_texture = nullptr;
        int m_width = 0;
        int m_height = 0;
    };
} // namespace Retronomicon