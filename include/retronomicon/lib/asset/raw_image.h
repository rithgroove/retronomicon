#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;
/**
 * This namespace is for handling asset loading 
 */
namespace retronomicon::lib::asset{
    /**
     *  A class that represent a loaded image from storage to memory
     */    
    class RawImage {
        public:
            RawImage(string imagePath,string name,SDL_Renderer* renderer); // Constructor: accept path to image and build SDL_Texture, store the width and the height too
            ~RawImage(); // Destructor: remove sdl texture

            int getWidth() const; // Get image width
            int getHeight() const; // Get image height
            SDL_Texture* getTexture() const; // Get the texture
            string getName() ;
            string getPath() ;
        private:
            string m_imagePath;
            string m_name;
            SDL_Texture* m_texture = nullptr; // The image loaded to texture for GPU use (not CPU, CPU use SDL_Surface)
            int m_width = 0; // The variable that store width
            int m_height = 0; // The variable that store height
    };
}