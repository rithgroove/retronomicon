#include "retronomicon/lib/asset/raw_image.h"

/**
 * @brief This namespace is for handling asset loading 
 */
namespace retronomicon::lib::asset{

    /**
     * @brief constructor for the raw image
     * 
     * @param imagePath the path to the image
     * @param the name of the image
     * @renderer used to generate texture from the surface (image files -> SDL_SURFACE -> SDL_TEXTURE)
     */
    RawImage::RawImage(const string& imagePath,const string& name,SDL_Renderer* renderer){
        m_imagePath = imagePath;
        m_name = name;

        // init sdl image PNG loader


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

    /**
     * @brief Destructor of the raw image
     * 
     * @param remove the sdl texture
     */
    RawImage::~RawImage(){
        if (m_texture) {
            SDL_DestroyTexture(m_texture); // destroy the texture to free the memory
            m_texture = nullptr;
        }
    }

    /**
     * @brief get the loaded texture
     * 
     * @return the image in texture format
     */
    SDL_Texture* RawImage::getTexture() const {
        return m_texture;
    }    

    /**
     * @brief get the width of the image 
     * 
     * @return the image width
     */
        int RawImage::getWidth() const {
        return m_width;
    }

    /**
     * @brief get the height of the image 
     * 
     * @return the image height
     */
    int RawImage::getHeight() const {
        return m_height;
    }

    /**
     * @brief get the name of the image 
     * 
     * @return the name of the image
     */
    string RawImage::getName()  {

        cout << "getName " << endl;
        cout << &m_name << endl;
        cout <<"name = " << m_name << endl;
        return m_name;
    }

    /**
     * @brief get the filepath to the image
     * 
     * @return the filepath of the image
     */
    string RawImage::getPath()  {
        cout << "getPath" << endl;
        return m_imagePath;
    }
}