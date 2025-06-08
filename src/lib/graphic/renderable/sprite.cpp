#include "retronomicon/lib/graphic/renderable/sprite.h"
#include "retronomicon/lib/asset/font.h"
#include <iostream>
/**
 * This namespace is for handling asset loading 
 */
namespace retronomicon::lib::graphic::renderable{
            
    /*************************************************************************************************
     * Constructor: initialize the font (TTF_Font)   
     *************************************************************************************************/
    Sprite::Sprite(RawImage* image, Rect* rect){
        m_rawImage = image;
        m_rect = rect;
        m_flip = false;
    }

    /*************************************************************************************************
     * Destructor: remove the font
     *************************************************************************************************/
    // Sprite::~Sprite() {
    //     //TTF_Quit(); //might need this later
    // }

    /*************************************************************************************************
     * Update function
     *************************************************************************************************/
    bool Sprite::update(){
        return true;
    } 

    /*************************************************************************************************
     * Render function
     *************************************************************************************************/
    bool Sprite::render(SDL_Renderer* m_renderer){
        SDL_Rect dstRect = m_rect->generateSDLRect();
        SDL_RendererFlip flip = SDL_FLIP_NONE ;
        cout << ("render") << endl;
        if (m_flip){
            cout << ("flip") << endl;
            flip = SDL_FLIP_HORIZONTAL;   
        }
        SDL_RenderCopyEx(m_renderer, m_rawImage->getTexture(), nullptr, &dstRect, 0.0, nullptr, flip);
    } 

    bool Sprite::getFlip(){
        return m_flip;
    }

    bool Sprite::flip(){
            cout << ("\npanggil flip") << endl;
        m_flip = !m_flip;
        return m_flip;
    }

}