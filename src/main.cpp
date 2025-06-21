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
#include "retronomicon/lib/graphic/animation/frame.h"
#include "retronomicon/lib/graphic/animation/sequence.h"
#include "retronomicon/lib/math/rect.h"
#include "retronomicon/lib/core/game_object.h"
#include "retronomicon/lib/core/system/render_system.h"
#include "retronomicon/lib/core/component/transform_component.h"
#include "retronomicon/lib/core/component/sprite_component.h"
#include "retronomicon/lib/core/scene.h"

// #include "retronomicon.lib.asset.asset_manager.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
using namespace retronomicon::lib::asset;
using namespace retronomicon::lib::graphic::animation;
using namespace retronomicon::lib::math;

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

    if (TTF_Init() == -1) {
        std::cerr << "TTF_Init failed: " << TTF_GetError() << std::endl;
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        std::cerr << "IMG_INIT failed: " << TTF_GetError() << std::endl;
    }

    retronomicon::lib::graphic::Window window("My SDL2 Game", SCREEN_WIDTH, SCREEN_HEIGHT); 

    SDL_Renderer *ren = window.getRenderer();
    AssetManager* temp = new AssetManager(ren);

    // load building
    RawImage* test =temp->loadImage("./asset/sprite/building2.png", "building2");
    if (test){
        cout << "good" << endl;
    }else{
        cout << "bad" << endl;
    }

    // load character
    RawImage* miho = temp->loadImage("./asset/sprite/miho-test.png", "miho");
    if (miho){
        cout << "good" << endl;
    }else{
        cout << "bad" << endl;
    }

    Font * main_font = temp->loadFont("./asset/font/Code38-manaspace/manaspc.ttf","ManaSpace",16);

    vector<Frame>frames;
    frames.push_back(Frame(0,0,64,64,0,"miho-standby",200.0));
    frames.push_back(Frame(64,0,64,64,1,"miho-standby",200.0));
    frames.push_back(Frame(128,0,64,64,2,"miho-standby",200.0));
    frames.push_back(Frame(192,0,64,64,3,"miho-standby",200.0));
    frames.push_back(Frame(256,0,64,64,4,"miho-standby",200.0));
    Sequence* seq = new Sequence (frames, 5, "miho-standby", true);
    SequenceManager* seqMan = new SequenceManager(seq);

    Scene* scene = new Scene("testing");
    RenderSystem* render_system = new RenderSystem(ren);
    scene->addSystem(render_system);

    GameObject* obj1 = scene->createGameObject("Miho");
    TransformComponent* objTransform = obj1->addComponent<TransformComponent>(450,300,0.0f,2.0f,2.0f);
    SpriteComponent *obj1Sprite = obj1->addComponent<SpriteComponent>(miho, seqMan);
    objTransform->setRotation(45.0f);
    obj1->start();

    GameObject* obj2 = scene->createGameObject("Building");
    TransformComponent* obj2Transform = obj2->addComponent<TransformComponent>(50,50,0.0f,1.0f,1.0f);
    obj2Transform->setRotation(90.0f);
    SpriteComponent *obj2Sprite = obj2->addComponent<SpriteComponent>(test);
    obj2->start();


    SDL_Color fgC1 = { 0xff,0xff,0xff }, bgC1 = {0x00,0x00,0xa0};       
    bool eQuit = false;
    std::cout <<"\nmain loop"<<std::endl;
    SDL_Rect fillRect = { SCREEN_WIDTH  / 4, SCREEN_HEIGHT / 4,
                              SCREEN_WIDTH/2, SCREEN_HEIGHT / 2 };
    SDL_Rect fillrect2= { 5, 280, 630, 190 };

    Uint64 currentTime = SDL_GetPerformanceCounter();
    Uint64 lastTime = 0;
    double deltaTime = 0.0;

    while (!eQuit) {
        lastTime = currentTime;
        currentTime = SDL_GetPerformanceCounter();
        deltaTime = static_cast<double>(currentTime - lastTime) / SDL_GetPerformanceFrequency();
        deltaTime *= 1000;
        std::cout <<"\nmasuk while\n"<<std::endl;

        SDL_SetRenderDrawColor(ren, 78, 215, 241, 255);
        SDL_RenderClear(ren);

        // Draw and animate
        SDL_SetRenderDrawColor(ren, 111, 230, 252, 255);
        SDL_RenderFillRect(ren, &fillRect);

        std::cout <<"\nmasuk render text\n"<<std::endl;
        SDL_Texture* texture = main_font->generateTexture( "Hello Dum dum! ",5,5,630,190,fgC1,bgC1);
        std::cout <<"\ndone render text1\n"<<std::endl;
        SDL_RenderCopy(ren,texture, NULL,&fillrect2);
        std::cout <<"\ndone render text2\n"<<std::endl;
        SDL_DestroyTexture(texture);

        std::cout <<"\ndone render text3\n"<<std::endl;

        scene->update(deltaTime);
        scene->render();

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
        SDL_Delay(200); // Keep < 500 [ms]
    }
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    return 0;
}