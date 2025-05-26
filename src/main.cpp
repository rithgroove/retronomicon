#include "retronomicon/lib/graphic/window.h"
#include "retronomicon/lib/graphic/font.h"
#include <SDL.h>
#include <stdio.h>
#include <png.h>


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int width, height;
png_byte color_type;
png_byte bit_depth;
png_bytep *row_pointers = NULL;
unsigned char * image = NULL;

void read_png_file(char *filename) {
  FILE *fp = fopen(filename, "rb");

  png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if(!png) abort();

  png_infop info = png_create_info_struct(png);
  if(!info) abort();

  if(setjmp(png_jmpbuf(png))) abort();

  png_init_io(png, fp);

  png_read_info(png, info);

  width      = png_get_image_width(png, info);
  height     = png_get_image_height(png, info);
  color_type = png_get_color_type(png, info);
  bit_depth  = png_get_bit_depth(png, info);
  int numchan = 4;
  printf("width = %d\n",width);
  printf("height = %d\n",height);
  printf("color_type = %d\n",color_type);
  printf("bit_depth = %d\n",bit_depth);
  // Read any color_type into 8bit depth, RGBA format.
  // See http://www.libpng.org/pub/png/libpng-manual.txt

  if(bit_depth == 16)
    png_set_strip_16(png);

  if(color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_palette_to_rgb(png);

  // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
  if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
    png_set_expand_gray_1_2_4_to_8(png);

  if(png_get_valid(png, info, PNG_INFO_tRNS))
    png_set_tRNS_to_alpha(png);

  // These color_type don't have an alpha channel then fill it with 0xff.
  if(color_type == PNG_COLOR_TYPE_RGB ||
     color_type == PNG_COLOR_TYPE_GRAY ||
     color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

  if(color_type == PNG_COLOR_TYPE_GRAY ||
     color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
    png_set_gray_to_rgb(png);

  png_read_update_info(png, info);

  if (row_pointers) abort();

  row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
  for(int y = 0; y < height; y++) {
    row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
  }
    
    // Put row pointers data into image
  int count = 0;
    image = (unsigned char *) malloc (numchan*width*height);
    for (unsigned int i=0;i<height;i++){
        for (unsigned int j=0;j<width;j++){
            image[count] = row_pointers[i][j];
            count++;
        }
    }


  png_read_image(png, row_pointers);

  fclose(fp);

  png_destroy_read_struct(&png, &info, NULL);
}




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

SDL_Texture* renderText (retronomicon::lib::graphic::Font main_font,SDL_Renderer *ren, SDL_Surface* screen, char* string,int x, int y, SDL_Color fgC, SDL_Color bgC) {
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

    SDL_Texture* texture = SDL_CreateTextureFromSurface(ren,textSurface);
    SDL_FreeSurface(textSurface);
    return texture;
    //printf("[ERROR] Unknown error in drawText(): %s\n", TTF_GetError()); return 1;
}

int main(int argc, char* argv[]) {
    retronomicon::lib::graphic::Window window("My SDL2 Game", SCREEN_WIDTH, SCREEN_HEIGHT); //directly initiate to a variable named "window"
    SDL_Event wEvent;                               // Enable the Window Event handler...
    SDL_Surface* screenSurface = SDL_GetWindowSurface(window.getRawWindow());

    retronomicon::lib::graphic::Font main_font("./asset/font/Code38-manaspace/manaspc.ttf",16); //directly initiate to a variable named "main_font"
    SDL_Color fgC1 = { 0xff,0xff,0xff }, bgC1 = {0x00,0x00,0xa0};                               // white text on blue background
    printf("\ndraw text");  
    fflush(stdout);


    read_png_file((char*)"./asset/sprite/miho-test.png");
    
    printf("\nDelay");  
    fflush(stdout);
    SDL_Delay(1000);  // Wait 1 sec for greasy fingers
    bool eQuit = false;
    printf("\nmain loop");  
    fflush(stdout);
    while (!eQuit) {
        printf("\nmasuk while\n");
        fflush(stdout);


        SDL_Renderer *ren = window.getRenderer();
        SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
        SDL_RenderClear(ren);


        // Draw and animate
        SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
        SDL_Rect fillRect = { SCREEN_WIDTH  / 4, SCREEN_HEIGHT / 4,
                                  SCREEN_WIDTH/2, SCREEN_HEIGHT / 2 };
        SDL_RenderFillRect(ren, &fillRect);

        SDL_Texture* texture = renderText(main_font,ren,screenSurface, (char*) "Hello Dum dum! ",50,50,fgC1,bgC1);
        fillRect = { 50, 50, 300,  100 };
        SDL_RenderCopy(ren,texture, NULL,&fillRect);


        // printf(&row_pointers);
        SDL_Texture *Tile = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888,
                        SDL_TEXTUREACCESS_STREAMING, 1, 1);
        int pitch = 0;
        SDL_LockTexture(Tile, nullptr, reinterpret_cast<void**>(&image), &pitch);
        SDL_UnlockTexture(Tile);

        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        SDL_Rect destination = { 320, 240, 256, 256 };
        SDL_RenderCopy(ren, Tile, NULL, &destination);

        window.present();



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