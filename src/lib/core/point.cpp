#include "retronomicon/lib/core/point.h"
// #include <cmath>

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::core{

    /**
     * @brief constructor with 2 points 
     * 
     * @param x the x position
     * @param y the y position
     */
    Point::Point(float x, float y){
        set(x,y);
    }

    /**
     * @brief a function to change the position of the points
     * 
     * @param x the x position
     * @param y the y position
     */
    void Point::set(float x,float y){
        m_x = x;
        m_y = y;
    }

    /**
     * @brief return the x position of the point
     * 
     * @return the x position of the point
     */
    float Point::getX() const {
        return m_x;
    }

    /**
     * @brief return the y position of the point
     * 
     * @return the y position of the point
     */
    float Point::getY() const {
        return m_y;
    }

    /**
     * @brief calculate the distance between this point and target point
     * 
     * @param target the target point
     * @return the distance in float
     */
    float Point::calculateDistance(Point* target){
        float distance_x = abs((m_x - target->getX()));
        float distance_y = abs((m_y - target->getY()));
        return sqrt((distance_x*distance_x) + (distance_y*distance_y));
    }
}