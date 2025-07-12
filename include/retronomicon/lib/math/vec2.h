#pragma once
#include <ostream>

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::math {

    /**
     * @brief A class that represent a 2D vector 
     */
    class Vec2 {
        public:
            /***************************** Attribute *****************************/

            float x, y; // because Vec2 values changes a lot we put it in public

            /***************************** Constructor *****************************/

            /**
             * @brief default constructor (0,0)
             */
            Vec2() : x(0), y(0) {}
 
            /**
             * @brief constructor (x,y)
             * 
             * @param x value
             * @param y value
             */
            Vec2(float x, float y) : x(x), y(y) {}

            // Vector addition/subtraction
            Vec2 operator+(const Vec2& other) const;

            Vec2 operator-(const Vec2& other) const;

            Vec2& operator+=(const Vec2& other);

            Vec2& operator-=(const Vec2& other);
            // Scalar multiplication/division
            Vec2 operator*(float scalar) const;
            Vec2 operator/(float scalar) const;
            Vec2& operator*=(float scalar);

            Vec2& operator/=(float scalar) ;

            // Magnitude and normalization
            float length() const;

            Vec2 normalized() const;

            float dot(const Vec2& other) const;
            // Utility
            bool isZero() const;

            friend std::ostream& operator<<(std::ostream& os, const Vec2& v);
    };

} // namespace retronomicon::lib::math
