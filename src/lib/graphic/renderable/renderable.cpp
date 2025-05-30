#include "retronomicon/lib/graphic/renderable/sprite.h"
#include <iostream>

namespace retronomicon::lib::graphic{
    
    void Renderable::setPosition(int x, int y){
        m_x = x;
        m_y = y;
    }

    int Renderable::getX(){
        return m_x;
    }
    int Renderable::getY(){
        return m_y;
    }
    int Renderable::getHeight(){
        return m_height;
    }

    int Renderable::getWidth(){
        return m_width;
    }

    float Renderable::getScale(){
        return m_scale;
    } 

}