#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;
/**
 * @brief This namespace is for handling asset loading 
 */
namespace retronomicon::lib::asset{
    /**
     *  @brief A class that represent a loaded image from storage to memory
     */    
    class RawImage {
        public:
            /**
             * @brief constructor for the raw image
             * 
             * @param imagePath the path to the image
             * @param the name of the image
             * @renderer used to generate texture from the surface (image files -> SDL_SURFACE -> SDL_TEXTURE)
             */
            RawImage(const string& imagePath,const string& name, SDL_Renderer* renderer); 

            /**
             * @brief Destructor of the raw image
             * 
             * @param remove the sdl texture
             */
            ~RawImage(); 

            /**
             * @brief get the width of the image 
             * 
             * @return the image width
             */
            int getWidth() const;

            /**
             * @brief get the height of the image 
             * 
             * @return the image height
             */
            int getHeight() const;

1            /**
             * @brief get the loaded texture
             * 
             * @return the image in texture format
             */
            SDL_Texture* getTexture() const; 
 
            /**
             * @brief get the name of the image 
             * 
             * @return the name of the image
             */
            string getName() ;

            /**
             * @brief get the filepath to the image
             * 
             * @return the filepath of the image
             */
            string getPath() ;
        private:
            string m_imagePath;
            string m_name;
            SDL_Texture* m_texture = nullptr; // The image loaded to texture for GPU use (not CPU, CPU use SDL_Surface)
            int m_width = 0; // The variable that store width
            int m_height = 0; // The variable that store height
    };
}