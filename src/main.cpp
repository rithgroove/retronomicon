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
#include "retronomicon.lib.asset.asset_manager.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

static void die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap,fmt); 
    
    vfprintf(stderr, fmt, ap);
    exit(-1);
}

int main(int argc, char* argv[])
{
	retronomicon::lib::asset::AssetManager
    return 0;
}