#include "retronomicon/lib/graphic/window.h"
#include "retronomicon/lib/graphic/font.h"
#include <SDL.h>
#include <stdio.h>


void drawText (retronomicon::lib::graphic::Font main_font, SDL_Surface* screen, char* string, int size, int x, int y, SDL_Color fgC, SDL_Color bgC) {
    // Remember to call TTF_Init(), TTF_Quit(), before/after using this function.

    // TTF_Font* font = main_font.getRawFont();
    // TTF_Font* font = TTF_OpenFont("./asset/font/Code38-manaspace/manaspc.ttf", size);
    TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/liberation/LiberationSansNarrow-Bold.ttf", size);
    if(!font) {
        printf("[ERROR] TTF_OpenFont() Failed with: %s\n", TTF_GetError());
        exit(2);
    }

    TTF_SetFontStyle(font, TTF_STYLE_BOLD);
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, string, fgC);     // aliased glyphs
    // SDL_Surface* textSurface = TTF_RenderText_Shaded(font, string, fgC, bgC);   // anti-aliased glyphs
    SDL_Rect textLocation = { x, y, 0, 0 };
    if (SDL_BlitSurface(textSurface, NULL, screen, &textLocation) == 0){
        printf("\nsuccess to blit surface");
        fflush(stdout);
    }else{
        printf("\nfailed to blit surface");
        fflush(stdout);

    }
    SDL_FreeSurface(textSurface);
    //printf("[ERROR] Unknown error in drawText(): %s\n", TTF_GetError()); return 1;
}

int main(int argc, char* argv[]) {
    retronomicon::lib::graphic::Window window("My SDL2 Game", 800, 600); //directly initiate to a variable named "window"
    SDL_Event wEvent;                               // Enable the Window Event handler...
  
    SDL_Surface* screenSurface = SDL_GetWindowSurface(window.getRawWindow());
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x80, 0x00, 0x00));     // Set a blue background canvas
    SDL_UpdateWindowSurface(window.getRawWindow());

    printf("ready yuk\n");
    bool running = true;
    SDL_Event event;
    retronomicon::lib::graphic::Font main_font("./asset/font/Code38-manaspace/manaspc.ttf",200); //directly initiate to a variable named "main_font"
    if (main_font.isInitialized()){
        printf("main font is loaded");
    }else{
        printf("main font fails to load");
    }

    fflush(stdout);
    SDL_Color fgC1 = { 0xff,0xff,0xff }, bgC1 = {0x00,0x00,0xa0};                               // white text on blue background
    SDL_Color fgC2 = { 0x00,0x00,0x00 }, bgC2 = {0xff,0x00,0xff};     
    drawText(main_font, screenSurface, (char*) "Hello Dum dum! ", 40,  50, 50, fgC1, bgC1);  // 18 pt @ (x=50,y=100)
    // drawText(main_font, screenSurface, (char*) "manacpc.ttf @ (x=200, y=150)",   16, 200, 175, fgC2, bgC2);  // 16 pt @ (x=200,y=150)
    SDL_UpdateWindowSurface(window.getRawWindow());

    SDL_Delay(1000);  // Wait 1 sec for greasy fingers
    bool eQuit = false;
    while (!eQuit) {
        while(SDL_PollEvent(&wEvent)) {
            switch (wEvent.type) {
                case SDL_QUIT:              eQuit = true; break;
                case SDL_KEYDOWN:           eQuit = true; break;
                case SDL_MOUSEBUTTONDOWN:   eQuit = true; break;
                case SDL_WINDOWEVENT_CLOSE: eQuit = true; break;
            default:
                //SDL_Log("Window %d got unknown event %d\n", wEvent.window.windowID, wEvent.window.event);
                break;
            }
        }
        SDL_Delay(100); // Keep < 500 [ms]
    }


    return 0;
}