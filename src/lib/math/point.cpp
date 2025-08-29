#include "retronomicon/lib/math/point.h"
#include <cmath>
#include <sstream>

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::math{

    /***************************** Constructor *****************************/

    /**
     * @brief constructor with 2 points 
     * 
     * @param vector the Vec2 we wanted to convert to Point
     */
    Point::Point(const Vec2& vector) noexcept 
        : m_x(vector.x),m_y(vector.y){}

    /***************************** Destructor *****************************/

    // Point:~Point() = default; //put it here in case needed

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
    float Point::calculateDistance(const Point& target) const noexcept{
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
    Vec2 Point::toVec2() const noexcept{
        return Vec2{m_x, m_y};
    }
}