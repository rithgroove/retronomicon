#include "retronomicon/lib/graphic/window.h"
#include "retronomicon/lib/graphic/font.h"
#include <SDL.h>
#include <stdio.h>


void drawText (retronomicon::lib::graphic::Font main_font, SDL_Surface* screen, char* string, int size, int x, int y, SDL_Color fgC, SDL_Color bgC) {
    TTF_SetFontStyle(main_font.getRawFont(), TTF_STYLE_BOLD);
    SDL_Surface* textSurface = TTF_RenderText_Solid(main_font.getRawFont(), string, fgC);     // aliased glyphs
    // SDL_Surface* textSurface = TTF_RenderText_Shaded(main_font.getRawFont(), string, fgC, bgC);   // anti-aliased glyphs
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

    // printf("ready yuk\n");
    retronomicon::lib::graphic::Font main_font("./asset/font/Code38-manaspace/manaspc.ttf",16); //directly initiate to a variable named "main_font"
    SDL_Color fgC1 = { 0xff,0xff,0xff }, bgC1 = {0x00,0x00,0xa0};                               // white text on blue background
    // SDL_Color fgC2 = { 0x00,0x00,0x00 }, bgC2 = {0xff,0x00,0xff};     
    drawText(main_font, screenSurface, (char*) "Hello Dum dum! ", 40,  50, 50, fgC1, bgC1);  // 18 pt @ (x=50,y=100)

    // drawText(main_font, screenSurface, (char*) "Hello Dum dum! ", 40,  50, 50, { 0xff,0xff,0xff }, {0x00,0x00,0xa0});      // drawText(main_font, screenSurface, (char*) "manacpc.ttf @ (x=200, y=150)",   16, 200, 175, fgC2, bgC2);  // 16 pt @ (x=200,y=150)
    SDL_UpdateWindowSurface(window.getRawWindow());

    SDL_Delay(1000);  // Wait 1 sec for greasy fingers
    bool eQuit = false;
    while (!eQuit) {
        printf("masuk while\n");
        fflush(stdout);
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