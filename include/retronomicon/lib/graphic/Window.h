#pragma once

#include <SDL2/SDL.h>
#include <string>

namespace retronomicon {
    namespace lib{
        namespace graphic{
            class Window {
                public:
                    Window(const std::string& title, int width, int height, bool fullscreen = false);
                    ~Window();

                    void clear();
                    void present();
                    void toggleFullscreen();
                    void handleResize(int newWidth, int newHeight);

                    int getWidth() const;
                    int getHeight() const;
                    SDL_Renderer* getRenderer() const;
                    SDL_Window* getRawWindow() const;

                private:
                    void initialize(const std::string& title, int width, int height, bool fullscreen);
                    void cleanup();

                    SDL_Window* m_window = nullptr;
                    SDL_Renderer* m_renderer = nullptr;
                    int m_width = 0;
                    int m_height = 0;
                    bool m_fullscreen = false;
            };
        }
    }
} // namespace Retronomicon