#include "retronomicon/lib/math/point.h"
// #include <cmath>

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::math{

    /**
     *  @brief default constructor with x=0 and y =0
     */
    Point::Point() : m_x(0.0f), m_y(0.0f) {}

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
     * @brief calculate the distance between this point and target point
     * 
     * @param target the target point
     * @return the distance in float
     */
    float Point::calculateDistance(const Point& target) const {
        float dx = m_x - target.getX();
        float dy = m_y - target.getY();
        return std::sqrt(dx * dx + dy * dy);
    }

    /**
     * @brief overloading operator == 
     * 
     * @param other another point
     */
    bool Point::operator==(const Point& other) const {
        return m_x == other.m_x && m_y == other.m_y;
    }

    /**
     * @brief overloading operator != 
     * 
     * @param other another point
     */
    bool Point::operator!=(const Point& other) const {
        return !(*this == other);
    }

    /**
     * @brief overloading operator + 
     * 
     * @param other another point
     */
    Point Point::operator+(const Point& other) const {
        return Point(m_x + other.m_x, m_y + other.m_y);
    }

    /**
     * @brief overloading operator - 
     * 
     * @param other another point
     */
    Point Point::operator-(const Point& other) const {
        return Point(m_x - other.m_x, m_y - other.m_y);
    }
}