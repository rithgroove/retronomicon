#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdexcept>
#include <iostream>

/**
 * This namespace is for handling asset loading 
 */
namespace retronomicon::lib::asset{
    /**
     *  A class that represent a loaded image from storage to memory
     */    
    class RawImage {
        public:

            RawImage(const std::string& imagePath,const std::string& name); // Constructor: accept path to image and build SDL_Texture, store the width and the height too
            ~RawImage(); // Destructor: remove sdl texture

            int getWidth() const; // Get image width
            int getHeight() const; // Get image height
            SDL_Texture* getTexture() const; // Get the texture
            std::string* getName();
            std::string* getPath();
        private:
            std::string* m_imagePath;
            std::string* m_name;
            SDL_Texture* m_texture = nullptr; // The image loaded to texture for GPU use (not CPU, CPU use SDL_Surface)
            int m_width = 0; // The variable that store width
            int m_height = 0; // The variable that store height
    };
}