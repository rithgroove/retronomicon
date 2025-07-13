#include "retronomicon/lib/math/vec2.h"
#include <cmath>

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::math {

    /***************************** Utility *****************************/

    /**
     * @brief a method to check if this is a zero vector
     *      
     * @return true if zero
     */ 
    bool Vec2::isZero() const {
        return x == 0.0f && y == 0.0f;
    }

    /***************************** Operator Overload *****************************/

    /**
     * @brief overloading operator + 
     * 
     * @param other another vec2
     */
    Vec2 Vec2::operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    /**
     * @brief overloading operator - 
     * 
     * @param other another vec2
     */
    Vec2 Vec2::operator-(const Vec2& other) const {
        return Vec2(x - other.x, y - other.y);
    }

    /**
     * @brief overloading operator +=
     * 
     * @param other another vec2
     */
    Vec2& Vec2::operator+=(const Vec2& other) {
        x += other.x; y += other.y;
        return *this;
    }

    /**
     * @brief overloading operator -=
     * 
     * @param other another vec2
     */
    Vec2& Vec2::operator-=(const Vec2& other) {
        x -= other.x; y -= other.y;
        return *this;
    }

    /**
     * @brief overloading operator * with scalar
     * 
     * @param scalar the scalar value
     */
    Vec2 Vec2::operator*(float scalar) const {
        return Vec2(x * scalar, y * scalar);
    }

    /**
     * @brief overloading operator / with scalar
     * 
     * @param scalar the scalar value
     */
    Vec2 Vec2::operator/(float scalar) const {
        return Vec2(x / scalar, y / scalar);
    }

    /**
     * @brief overloading operator *= with scalar
     * 
     * @param scalar the scalar value
     */
    Vec2& Vec2::operator*=(float scalar) {
        x *= scalar; y *= scalar;
        return *this;
    }

    /**
     * @brief overloading operator /= with scalar
     * 
     * @param scalar the scalar value
     */
    Vec2& Vec2::operator/=(float scalar) {
        x /= scalar; y /= scalar;
        return *this;
    }

    /***************************** To String *****************************/
    
    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string Vec2::to_string() const{
        std::ostringstream oss;
        oss << "[Vector]\n";
        oss << "values:\n";
        oss << "- x = "<< x <<"\n";
        oss << "- y = "<< y <<"\n";
        oss << "- length = "<< length() <<"\n";
        return oss.str();
    }

    /***************************** Main Methods *****************************/

    /**
     * @brief a method to calculate the length of this vector
     * 
     * @return the length of this vector
     */ 
    float Vec2::length() const {
        return std::sqrt(x * x + y * y);
    }

    /**
     * @brief a method to calculate the normalized vector of this vector
     * to put it simply we want a smaller vector that focused more on the direction
     * compared to distance.
     * 
     * @return the normalized vector (magnitude 1 vector)
     */ 
    Vec2 Vec2::normalized() const {
        float len = length();
        if (len == 0.0f) return Vec2(0, 0);
        return *this / len;
    }

    /**
     * @brief a method to calculate the dot product of this vector with another vector.
     * The dot product, also known as the scalar product or inner product, 
     * is a way to multiply two vectors to produce a single number (scalar). 
     * It measures the extent to which two vectors point in the same direction. 
     * 
     * how to interpret the result:
     * - Positive result: Indicates that the vectors are generally pointing in the same direction.
     * - Zero result: Indicates that the vectors are orthogonal (perpendicular) to each other.
     * - Negative result: Indicates that the vectors are generally pointing in opposite directions. 
     * 
     * @return the scalar representation of the dot product
     */ 
    float Vec2::dot(const Vec2& other) const {
        return x * other.x + y * other.y;
    }

}