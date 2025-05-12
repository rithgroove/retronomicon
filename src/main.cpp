//======================================================================
// A sdl2 program that draws a white window with a red circle.
//
// 2024-09-09 Mon
// Dov Grobgeld <dov.grobgeld@gmail.com>
//----------------------------------------------------------------------

#include <SDL.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

static void die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap,fmt); 
    
    vfprintf(stderr, fmt, ap);
    exit(-1);
}

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char* argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        die("SDLInit Error: %s\n", SDL_GetError());

    // Create a window
    SDL_Window *win = SDL_CreateWindow("Hello, World!",
                                       SDL_WINDOWPOS_UNDEFINED,
                                       SDL_WINDOWPOS_UNDEFINED,
                                       SCREEN_WIDTH, SCREEN_HEIGHT,
                                       SDL_WINDOW_FOREIGN);

    if (win == NULL) 
        die("SDL_CreateWindow Error: %s\n", SDL_GetError());

    // Create a renderer
    //SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);

    // Setup t0 time using SDL
    Uint32 t0 = SDL_GetTicks();

    if (ren == NULL) 
        die("SDL_CreateRenderer Error: %s\n", SDL_GetError());

    // Event loop
    SDL_bool quit = SDL_FALSE;
    while (!quit) {

        // Poll for events with timeout of 100ms
        SDL_Event e = { .type=0 };
        SDL_WaitEventTimeout(&e, 10);

        switch (e.type) {
            case SDL_QUIT:
                quit = SDL_TRUE;
                break;
            default:
                break;
        }

        Uint32 t1 = SDL_GetTicks();
        Uint32 elapsed = t1-t0;
        // Set draw the interface
        SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
        SDL_RenderClear(ren);

        // Draw and animate
        SDL_Rect fillRect = { SCREEN_WIDTH  / 4, SCREEN_HEIGHT / 4,
                              SCREEN_WIDTH/2, SCREEN_HEIGHT / 2 };
        SDL_RenderFillRect(ren, &fillRect);

        SDL_RenderPresent(ren);

        // Exit after 10 seconds
        if (elapsed > 10000)
            break;
    }    

    // Clean up
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
// #include "MyGame/core/Window.h"
// #include <SDL.h>

// int main() {
//     MyGame::Window window("My SDL2 Game", 800, 600);

//     bool isRunning = true;
//     SDL_Event event;

//     while (isRunning) {
//         while (SDL_PollEvent(&event)) {
//             if (event.type == SDL_QUIT)
//                 isRunning = false;

//             else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) {
//                 window.handleResize(event.window.data1, event.window.data2);
//             }

//             else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_f) {
//                 window.toggleFullscreen();
//             }
//         }

//         window.clear();

//         // draw...

//         window.present();
//     }

//     return 0;
// }
