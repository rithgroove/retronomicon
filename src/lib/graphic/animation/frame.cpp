#include "retronomicon/lib/graphic/animation/frame.h"
#include <iostream>
/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::graphic::animation{

    /**
     * @brief basic constructor
     * 
     * @param x the x position of the start of the current frame from the spritesheet
     * @param y the y position of the start of the current frame from the spritesheet
     * @param width the width of the current frame from the spritesheet
     * @param height the height of the current frame from the spritesheet
     * @param sequence_order (a number to indicate which frame number this is)
     * @param name the name of this frame
     */    
    Frame::Frame(int x, int y,int width, int height,int sequence_order, const string &name,float duration){
        m_rect = new Rect(x,y,width,height);
        m_sequence_order= sequence_order;
        m_name = name;
        m_duration = duration;
        m_spentDuration = 0.0f;
    }

    /**
     * @brief basic constructor
     * 
     * @param point the point representing the starting point of this frame
     * @param width the width of the current frame from the spritesheet
     * @param height the height of the current frame from the spritesheet
     * @param sequence_order (a number to indicate which frame number this is)
     * @param name the name of this frame
     */
    Frame::Frame(Point* point ,int width, int height,int sequence_order,const string &name,float duration){
        m_rect = new Rect(point,width,height);
        m_sequence_order= sequence_order;
        m_name = name;
        m_duration = duration;
        m_spentDuration = 0.0f;
    }

    /**
     * @brief basic constructor
     * 
     * @param rect the source rectangle of this frame
     * @param sequence_order (a number to indicate which frame number this is)
     * @param name the name of this frame
     */
    Frame::Frame(Rect* rect,int sequence_order,const string &name,float duration){
        m_rect = rect;
        m_sequence_order= sequence_order;
        m_name = name;
        m_duration = duration;
        m_spentDuration = 0.0f;
    }
    
    /**
     * @brief get the x position of this frame
     * 
     * @return x position
     */
    int Frame::getX() const {
        return m_rect->getX();
    }

    /**
     * @brief get the y position of this frame
     * 
     * @return y position
     */
    int Frame::getY() const {
        return m_rect->getY();
    }

    /**
     * @brief get the width of this frame
     * 
     * @return width
     */
    int Frame::getWidth() const {
        return m_rect->getWidth();
    }

    /**
     * @brief get the height of this frame
     * 
     * @return height
     */
    int Frame::getHeight() const {
        return m_rect->getHeight();
    }

    /**
     * the rectangle representing the source rectangle of the sprite
     * 
     * @return the source rectangle
     */
    Rect* Frame::getRect() const{
        return m_rect;
    }

    /**
     * @brief a method to reset spent duration (set m_spentDuration to 0)
     */
    void Frame::reset(){
        m_spentDuration = 0.0f;
    }

    /**
     * @brief check how many time spent on this frame
     * 
     * @return left over delta time
     */
    float Frame::update(float dt){
        cout<<"\n"<<m_spentDuration<<endl;
        m_spentDuration += dt;
        cout<<m_spentDuration<<"\n---------\n"<<endl;
        
        if (m_spentDuration > m_duration){
            cout<<"test"<<endl;
            float leftover =  m_spentDuration - m_duration; 
            this->reset();
            return leftover;
        }else{
            return 0.0f;
        }
    }
}