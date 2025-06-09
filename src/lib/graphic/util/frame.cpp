#include "retronomicon/lib/graphic/util/frame.h"

using namespace retronomicon::lib::core;
/**
 * The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::graphic::util{

    /*************************************************************************************************
     * Constructor: with all 4 int 
     *************************************************************************************************/
    Frame::Frame(int x, int y,int width, int height,RawImage* rawImage,int sequence_order, string &name){
        m_rect = new Rect(x,y,width,height);
        m_image = rawImage;
        m_sequence_order= sequence_order;
        m_name = name;
    }

    /*************************************************************************************************
     * Constructor: with points, width, height 
     *************************************************************************************************/
    Frame::Frame(Point* point ,int width, int height,RawImage* rawImage,int sequence_order, string &name){
        m_rect = new Rect(point,width,height);
        m_image = rawImage;
        m_sequence_order= sequence_order;
        m_name = name;
    }

    /*************************************************************************************************
     * Constructor: with points, width, height 
     *************************************************************************************************/
    Frame::Frame(Rect* rect,RawImage* rawImage,int sequence_order, string &name){
        m_rect = rect;
        m_image = rawImage;
        m_sequence_order= sequence_order;
        m_name = name;
    }

    /*************************************************************************************************
     * Get x position
     *************************************************************************************************/
    int Frame::getX() const {
        return m_rect->getX();
    }

    /*************************************************************************************************
     * Get y position
     *************************************************************************************************/
    int Frame::getY() const {
        return m_rect->getY();
    }

}