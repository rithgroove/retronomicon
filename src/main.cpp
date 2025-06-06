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
#include "retronomicon/lib/asset/asset_manager.h"
#include "retronomicon/lib/asset/font.h"
#include "retronomicon/lib/graphic/window.h"

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



    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        die("SDLInit Error: %s\n", SDL_GetError());

    retronomicon::lib::graphic::Window window("My SDL2 Game", SCREEN_WIDTH, SCREEN_HEIGHT); 

    AssetManager* temp = new AssetManager(window.getRenderer());
    
    if (temp->loadImage("./asset/sprite/miho-test.png", "miho")){
        cout << "good" << endl;
    }else{
        cout << "bad" << endl;
    }
    cout << ("miho" == "miho") << endl;
    RawImage* test = temp->getImage("miho");
    cout << "Crap" << endl;


    std::cout << test->getName() <<std::endl;
    std::cout << test->getPath() <<std::endl;
    cout << "Crap2" << endl;

    temp->loadFont("./asset/font/Code38-manaspace/manaspc.ttf","ManaSpace",16);

    Font * main_font = temp->getFont("ManaSpace",16);

    std::cout <<main_font->getName() <<std::endl;
    std::cout <<main_font->getPath() <<std::endl;
    

    SDL_Color fgC1 = { 0xff,0xff,0xff }, bgC1 = {0x00,0x00,0xa0};       
    bool eQuit = false;
    std::cout <<"\nmain loop"<<std::endl;
    while (!eQuit) {
        std::cout <<"\nmasuk while\n"<<std::endl;

        SDL_Renderer *ren = window.getRenderer();
        SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
        SDL_RenderClear(ren);


        // Draw and animate
        SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
        SDL_Rect fillRect = { SCREEN_WIDTH  / 4, SCREEN_HEIGHT / 4,
                                  SCREEN_WIDTH/2, SCREEN_HEIGHT / 2 };
        SDL_RenderFillRect(ren, &fillRect);

        SDL_Texture* texture = main_font->generateTexture( "Hello Dum dum! ",5,5,630,190,fgC1,bgC1);
        fillRect = { 5, 280, 630, 190 }; // render with 5 pixel from the left, 280 pixels from the top, for width and height minus padding
        SDL_RenderCopy(ren,texture, NULL,&fillRect);

        window.present();


        SDL_Event wEvent;   

        while(SDL_PollEvent(&wEvent)) {
            printf("masuk while2\n");
            fflush(stdout);
            switch (wEvent.type) {
                case SDL_QUIT:
                    eQuit = true; 
                    printf("sdl quit\n");
                    fflush(stdout);
                    break;
                case SDL_KEYDOWN:
                    eQuit = true; 
                    printf("sdl keydown\n");
                    fflush(stdout);
                    break;
                case SDL_MOUSEBUTTONDOWN:   
                    eQuit = true; 
                    printf("mouse down\n");
                    fflush(stdout);
                    break;
                case SDL_WINDOWEVENT_CLOSE: 
                    eQuit = true; 
                    printf("windows closed\n");
                    fflush(stdout);
                    break;
                default:
                    //SDL_Log("Window %d got unknown event %d\n", wEvent.window.windowID, wEvent.window.event);
                    printf("default\n");
                    break;
            }
        }
        SDL_Delay(100); // Keep < 500 [ms]
    }
    SDL_Quit();
    TTF_Quit();
    return 0;
}