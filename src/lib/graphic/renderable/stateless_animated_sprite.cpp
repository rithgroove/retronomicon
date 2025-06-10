#include "retronomicon/lib/graphic/renderable/stateless_animated_sprite.h"
#include <iostream>
/**
 * This namespace is for handling asset loading 
 */
namespace retronomicon::lib::graphic::renderable{
            
    /*************************************************************************************************
     * Constructor: initialize the font (TTF_Font)   
     *************************************************************************************************/
    StatelessAnimatedSprite::StatelessAnimatedSprite(RawImage* image, Rect* rect, Sequence* sequence)
    :Sprite(image,rect){
        m_sequence = sequence;
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
    bool StatelessAnimatedSprite::update(){
        m_sequence->update();
        return true;
    } 

    /*************************************************************************************************
     * Render function
     *************************************************************************************************/
    bool StatelessAnimatedSprite::render(SDL_Renderer* m_renderer){
        SDL_Rect dstRect = m_rect->generateSDLRect();
        SDL_RendererFlip flip = SDL_FLIP_NONE ;
        cout << ("render") << endl;
        if (m_flip){
            cout << ("flip") << endl;
            flip = SDL_FLIP_HORIZONTAL;   
        }
        SDL_Rect srcRect =  m_sequence->getCurrentFrame().getRect()->generateSDLRect();
        SDL_RenderCopyEx(m_renderer, m_rawImage->getTexture(), &srcRect, &dstRect, 0.0, nullptr, flip);
    } 


}