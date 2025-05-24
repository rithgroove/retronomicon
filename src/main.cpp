#include "retronomicon/lib/graphic/window.h"
#include <SDL.h>

int main(int argc, char* argv[]) {
    retronomicon::lib::graphic::Window window("My SDL2 Game", 800, 600);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_f) {
                window.toggleFullscreen();
            } else if (event.type == SDL_WINDOWEVENT &&
                       event.window.event == SDL_WINDOWEVENT_RESIZED) {
                window.handleResize(event.window.data1, event.window.data2);
            }
        }

        window.clear();

        // Game rendering here...

        window.present();
    }

    return 0;
}