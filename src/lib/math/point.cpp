#include "retronomicon/lib/math/point.h"
#include <cmath>
#include <sstream>

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::math{

    /***************************** Constructor *****************************/
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
    Point::Point(float x, float y) : m_x(x), m_y(y){}

    /**
     * @brief constructor with 2 points 
     * 
     * @param vector the Vec2 we wanted to convert to Point
     */
    Point::Point(Vec2& vector): m_x(vector.x),m_y(vector.y){}

    /***************************** Destructor *****************************/

    // Point:~Point() = default; //put it here in case needed

    /***************************** Operator Overload *****************************/

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

    /***************************** To String *****************************/

    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string Point::to_string() const{
        std::ostringstream oss;
        oss << "[Point]\n";
        oss << "values:\n";
        oss << "- x = "<< m_x <<"\n";
        oss << "- y = "<< m_y <<"\n";
        return oss.str();
    }

    /***************************** Main Methods *****************************/

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

    /***************************** Other Methods *****************************/
    
    /**
     * Convert point to Vec2
     * 
     * @return the vec2 representation of current point
     */
    Vec2 Point::toVec2() const {
        return Vec2{m_x, m_y};
    }
}