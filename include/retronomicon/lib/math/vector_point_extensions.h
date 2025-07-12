#pragma once

#include "point.h"
#include "vec2.h"

namespace retronomicon::lib::math {

    /***************************** Point *****************************/

    /**
     * @brief overload method for Point so it can be added with Vec2
     * 
     * @param p point (the first parameter)
     * @param v vec2 (the second parameter)
     * @return Point result (since it's point + vec2)
     */
    inline Point operator+(const Point& p, const Vec2& v) {
        return Point{p.x + v.x, p.y + v.y};
    }

    /**
     * @brief overload method for Point so it can be substracted with Vec2
     * 
     * @param p point (the first parameter)
     * @param v vec2 (the second parameter)
     * @return Point result (since it's point - vec2)
     */
    inline Point operator-(const Point& p, const Vec2& v) {
        return Point{p.x - v.x, p.y - v.y};
    }

    /***************************** Vector *****************************/

    /**
     * @brief overload method for Vec2 so it can be added with Point
     * 
     * @param v vec2 (the first parameter)
     * @param p point (the second parameter)
     * @return Point result (since it's point + vec2)
     */
    inline Vec2 operator+(const Vec2& v, const Point& p) {
        return (p+v).toVec2(); // reuse the method above
    }

    /**
     * @brief overload method for Vec2 so it can be substracted with Point
     * 
     * @param p point (the first parameter)
     * @param v vec2 (the second parameter)
     * @return Point result (since it's point - vec2)
     */
    inline Vec2 operator-(const Point& a, const Point& b) {
        return (p-v).toVec2(); // reuse the method above
    }

}