//======================================================================
// A sdl2 program that draws a white window with a red circle.
//
// 2024-09-09 Mon
// Dov Grobgeld <dov.grobgeld@gmail.com>
//----------------------------------------------------------------------

// #include <SDL.h>
#include <stdio.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <sol/sol.hpp>
#include <Python.h>

#include "retronomicon/lib/asset/raw_image.h"
#include "retronomicon/lib/asset/asset_manager.h"
#include "retronomicon/lib/asset/font.h"
#include "retronomicon/lib/graphic/window.h"
#include "retronomicon/lib/graphic/animation/frame.h"
#include "retronomicon/lib/graphic/animation/animation_clip.h"
#include "retronomicon/lib/math/rect.h"
#include "retronomicon/lib/core/game_object.h"
#include "retronomicon/lib/core/system/render_system.h"
#include "retronomicon/lib/core/system/animation_system.h"
#include "retronomicon/lib/core/system/input_system.h"
#include "retronomicon/lib/core/component/transform_component.h"
#include "retronomicon/lib/core/component/sprite_component.h"
#include "retronomicon/lib/core/component/animation_component.h"
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

void run_python_script() {
    Py_Initialize();

    // Run a simple script from string
    PyRun_SimpleString("print(\"Hello from Python!\")");

    Py_Finalize();
}

int main(int argc, char* argv[])
{

    sol::state lua;
    lua.open_libraries(sol::lib::base);

    lua.script("print('Hello from Lua!')");
    run_python_script();
    return 0;

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
    frames.push_back(Frame(0,0,64,64,0,"miho-standby",250.0));
    frames.push_back(Frame(64,0,64,64,1,"miho-standby",250.0));
    frames.push_back(Frame(128,0,64,64,2,"miho-standby",250.0));
    frames.push_back(Frame(192,0,64,64,3,"miho-standby",250.0));
    frames.push_back(Frame(256,0,64,64,4,"miho-standby",250.0));
    AnimationClip* clip = new AnimationClip (frames, 5, "miho-standby", true);

    Scene* scene = new Scene("testing");
    InputSystem* input_system = new InputSystem();
    scene->addSystem(input_system);
    scene->addSystem(new AnimationSystem());
    scene->addSystem(new RenderSystem(ren));

    GameObject* obj1 = scene->createGameObject("Miho");
    TransformComponent* objTransform = obj1->addComponent<TransformComponent>(450,300,0.0f,2.0f,2.0f);
    SpriteComponent *obj1Sprite = obj1->addComponent<SpriteComponent>(miho);
    AnimationComponent *obj1Sequence = obj1->addComponent<AnimationComponent>(clip);
    objTransform->setRotation(0.0f);
    obj1->start();

    GameObject* obj2 = scene->createGameObject("Building");
    TransformComponent* obj2Transform = obj2->addComponent<TransformComponent>(50,50,0.0f,1.0f,1.0f);
    obj2Transform->setRotation(0.0f);
    SpriteComponent *obj2Sprite = obj2->addComponent<SpriteComponent>(test);
    obj2->start();


    SDL_Color fgC1 = { 0xff,0xff,0xff }, bgC1 = {0x00,0x00,0xa0};       
    bool eQuit = false;
    std::cout <<"\nmain loop"<<std::endl;
    SDL_Rect fillRect = { SCREEN_WIDTH  / 4, SCREEN_HEIGHT / 4,
                              SCREEN_WIDTH/2, SCREEN_HEIGHT / 2 };
    SDL_Rect fillrect2= { 5, 50, 630, 190 };

    Uint64 currentTime = SDL_GetPerformanceCounter();
    Uint64 lastTime = 0;
    double deltaTime = 0.0;

    while (!eQuit) {
        lastTime = currentTime;
        currentTime = SDL_GetPerformanceCounter();
        deltaTime = static_cast<double>(currentTime - lastTime) / SDL_GetPerformanceFrequency();
        deltaTime *= 1000;

        SDL_SetRenderDrawColor(ren, 78, 215, 241, 255);
        SDL_RenderClear(ren);

        SDL_SetRenderDrawColor(ren, 111, 230, 252, 255);
        SDL_RenderFillRect(ren, &fillRect);

        scene->update(deltaTime);
        scene->render();

        // Draw and animate
        SDL_Texture* texture = main_font->generateTexture( "Hello Dum dum! ",5,5,630,190,fgC1,bgC1);
        SDL_RenderCopy(ren,texture, NULL,&fillrect2);
        SDL_DestroyTexture(texture);
        window.present();

        if (input_system->getInputStateForKey("quit")) {
            // Quit or pause
            eQuit = true; 
            printf("escape\n");
            fflush(stdout);
            break;
        }

       

    }
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    return 0;
}