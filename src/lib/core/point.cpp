#include "retronomicon/lib/core/point.h"
#include <cmath>

using namespace retronomicon::lib::core;
/**
 * The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::core{

    /*************************************************************************************************
     * Constructor: set m_x and m_y
     *************************************************************************************************/
    Point::Point(int x, int y){
        set(x,y);
    }

    /*************************************************************************************************
     * Constructor: change position of the point
     *************************************************************************************************/
    void Point::set(int x,int y){
        m_x = x;
        m_y = y;
    }

    /*************************************************************************************************
     * Get x position
     *************************************************************************************************/
    int Point::getX() const {
        return m_x;
    }

    /*************************************************************************************************
     * Get y position
     *************************************************************************************************/
    int Point::getY() const {
        return m_y;
    }


    /*************************************************************************************************
     * get float distance to a point 
     *************************************************************************************************/
    float Point::calculateDistance(Point* target){
        float distance_x = abs(((float) m_x - (float) target->getX()));
        float distance_y = abs(((float) m_y - (float) target->getY()));
        return sqrt((distance_x*distance_x) + (distance_y*distance_y));
    }
}