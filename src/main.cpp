//======================================================================
// A sdl2 program that draws a white window with a red circle.
//
// 2024-09-09 Mon
// Dov Grobgeld <dov.grobgeld@gmail.com>
//----------------------------------------------------------------------

// #include <SDL.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "retronomicon/lib/asset/raw_image.h"
#include "retronomicon/lib/asset/font.h"
// #include "retronomicon.lib.asset.asset_manager.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
using namespace retronomicon::lib::asset;

static void die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap,fmt); 
    
    vfprintf(stderr, fmt, ap);
    exit(-1);
}

int main(int argc, char* argv[])
{

    Font main_font("./asset/font/Code38-manaspace/manaspc.ttf","ManaSpace-16",16); 
    std::cout <<main_font.getName() <<std::endl;
    std::cout <<main_font.getPath() <<std::endl;


    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        die("SDLInit Error: %s\n", SDL_GetError());

    // Create a window
    SDL_Window *win = SDL_CreateWindow("Hello, World!",
                                       SDL_WINDOWPOS_UNDEFINED,
                                       SDL_WINDOWPOS_UNDEFINED,
                                       SCREEN_WIDTH, SCREEN_HEIGHT,
                                       SDL_WINDOW_FOREIGN);
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);

    if (win == NULL) 
        die("SDL_CreateWindow Error: %s\n", SDL_GetError());

    RawImage* test = new RawImage("./asset/sprite/miho-test.png", "miho", ren);
    std::cout <<test->getName() <<std::endl;
    std::cout <<test->getPath() <<std::endl;

    return 0;
}