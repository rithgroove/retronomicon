#include "retronomicon/lib/asset/raw_image.h"
// #include <iostream>

/**
 * This namespace is for handling asset loading 
 */
namespace retronomicon::lib::asset{

    /*************************************************************************************************
     * Constructor: accept path to image and build SDL_Texture, store the width and the height too 
     *************************************************************************************************/
    RawImage::RawImage(const string& imagePath,const string& name,SDL_Renderer* renderer){
        m_imagePath = imagePath;
        m_name = name;

        // init sdl image PNG loader
        if (IMG_Init(IMG_INIT_PNG) == 0) {
            throw std::runtime_error("Failed to initialize SDL_image: " + std::string(IMG_GetError()));
        }

        // load image to memory for CPU use
        SDL_Surface* surface = IMG_Load(m_imagePath.c_str());
        if (!surface) {
            throw std::runtime_error("Failed to load image: " + std::string(IMG_GetError()));
        }

        // move from cpu to gpu
        m_texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!m_texture) {
            SDL_FreeSurface(surface);
            throw std::runtime_error("Failed to create texture: " + std::string(SDL_GetError()));
        }

        m_width = surface->w; // store width
        m_height = surface->h; // store height

        SDL_FreeSurface(surface); // clear surface
    }

    /*************************************************************************************************
     * Destructor: remove sdl texture
     *************************************************************************************************/
    RawImage::~RawImage(){
        if (m_texture) {
            SDL_DestroyTexture(m_texture); // destroy the texture to free the memory
            m_texture = nullptr;
        }
    }

    /*************************************************************************************************
     * Get image width
     *************************************************************************************************/
    SDL_Texture* RawImage::getTexture() const {
        return m_texture;
    }

    /*************************************************************************************************
     * Get image width
     *************************************************************************************************/
    int RawImage::getWidth() const {
        return m_width;
    }

    /*************************************************************************************************
     * Get image height
     *************************************************************************************************/
    int RawImage::getHeight() const {
        return m_height;
    }

    /*************************************************************************************************
     * Get image name
     *************************************************************************************************/
    string RawImage::getName()  {

        cout << "getName " << endl;
        cout << &m_name << endl;
        cout <<"name = " << m_name << endl;
        return m_name;
    }

    /*************************************************************************************************
     * Get image file path
     *************************************************************************************************/
    string RawImage::getPath()  {
        cout << "getPath" << endl;
        return m_imagePath;
    }
}