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
#include <vector>
#include "retronomicon/lib/asset/raw_image.h"
#include "retronomicon/lib/asset/asset_manager.h"
#include "retronomicon/lib/asset/font.h"
#include "retronomicon/lib/graphic/window.h"
#include "retronomicon/lib/graphic/renderable/sprite.h"
#include "retronomicon/lib/graphic/renderable/stateless_animated_sprite.h"
#include "retronomicon/lib/graphic/util/frame.h"
#include "retronomicon/lib/graphic/util/sequence.h"
#include "retronomicon/lib/core/rect.h"

// #include "retronomicon.lib.asset.asset_manager.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
using namespace retronomicon::lib::asset;
using namespace retronomicon::lib::graphic::renderable;
using namespace retronomicon::lib::graphic::util;
using namespace retronomicon::lib::core;

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

    SDL_Renderer *ren = window.getRenderer();
    AssetManager* temp = new AssetManager(ren);
    
    if (temp->loadImage("./asset/sprite/building2.png", "building2")){
        cout << "good" << endl;
    }else{
        cout << "bad" << endl;
    }
    if (temp->loadImage("./asset/sprite/miho-test.png", "miho")){
        cout << "good" << endl;
    }else{
        cout << "bad" << endl;
    }
    cout << ("miho" == "miho") << endl;
    RawImage* test = temp->getImage("building2");
    cout << "Crap" << endl;

    Sprite* tempSprite = new Sprite(test,new Rect(50,50,test->getWidth(),test->getHeight()));

    std::cout << test->getName() <<std::endl;
    std::cout << test->getPath() <<std::endl;
    cout << "Crap2" << endl;

    temp->loadFont("./asset/font/Code38-manaspace/manaspc.ttf","ManaSpace",16);

    Font * main_font = temp->getFont("ManaSpace",16);

    std::cout <<main_font->getName() <<std::endl;
    std::cout <<main_font->getPath() <<std::endl;
    
    RawImage* miho = temp->getImage("miho");
    // string sequenceName = "miho-standby";

    vector<Frame>frames;
    frames.push_back(Frame(0,0,64,64,miho,0,"miho-standby"));
    frames.push_back(Frame(64,0,64,64,miho,1,"miho-standby"));
    frames.push_back(Frame(128,0,64,64,miho,2,"miho-standby"));
    frames.push_back(Frame(192,0,64,64,miho,3,"miho-standby"));
    frames.push_back(Frame(256,0,64,64,miho,4,"miho-standby"));

    Sequence * seq = new Sequence (frames, 5, "miho-standby", true);

    Sprite* tempSprite2 = new StatelessAnimatedSprite(miho, new Rect(220,300,128,128),seq);

    SDL_Color fgC1 = { 0xff,0xff,0xff }, bgC1 = {0x00,0x00,0xa0};       
    bool eQuit = false;
    std::cout <<"\nmain loop"<<std::endl;
    SDL_Rect fillRect = { SCREEN_WIDTH  / 4, SCREEN_HEIGHT / 4,
                              SCREEN_WIDTH/2, SCREEN_HEIGHT / 2 };
    SDL_Rect fillrect2= { 5, 280, 630, 190 };
    while (!eQuit) {
        std::cout <<"\nmasuk while\n"<<std::endl;

        SDL_SetRenderDrawColor(ren, 78, 215, 241, 255);
        SDL_RenderClear(ren);


        // Draw and animate
        SDL_SetRenderDrawColor(ren, 111, 230, 252, 255);
        SDL_RenderFillRect(ren, &fillRect);

        SDL_Texture* texture = main_font->generateTexture( "Hello Dum dum! ",5,5,630,190,fgC1,bgC1);
        SDL_RenderCopy(ren,texture, NULL,&fillrect2);
        SDL_DestroyTexture(texture);


        // tempSprite->flip();
        tempSprite->render(ren);
        tempSprite2->render(ren);
        window.present();
        tempSprite2->update();


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
        SDL_Delay(200); // Keep < 500 [ms]
    }
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}