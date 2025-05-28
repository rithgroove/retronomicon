#include "retronomicon/lib/graphic/sprite.h"
#include <iostream>

namespace retronomicon {
    namespace lib{
        namespace graphic{
            
            
            Sprite::Sprite(SDL_Renderer* renderer, const std::string& imagePath)
                : m_renderer(renderer) {
                if (IMG_Init(IMG_INIT_PNG) == 0) {
                    throw std::runtime_error("Failed to initialize SDL_image: " + std::string(IMG_GetError()));
                }

                SDL_Surface* surface = IMG_Load(imagePath.c_str());
                if (!surface) {
                    throw std::runtime_error("Failed to load image: " + std::string(IMG_GetError()));
                }

                m_texture = SDL_CreateTextureFromSurface(renderer, surface);
                if (!m_texture) {
                    SDL_FreeSurface(surface);
                    throw std::runtime_error("Failed to create texture: " + std::string(SDL_GetError()));
                }

                m_width = surface->w;
                m_height = surface->h;

                SDL_FreeSurface(surface);
            }

            Sprite::~Sprite() {
                if (m_texture) {
                    SDL_DestroyTexture(m_texture);
                    m_texture = nullptr;
                }
            }

            void Sprite::render(int x, int y, SDL_RendererFlip flip) {
                SDL_Rect dst = { x, y, m_width, m_height };
                render(dst, flip);
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
    }
}