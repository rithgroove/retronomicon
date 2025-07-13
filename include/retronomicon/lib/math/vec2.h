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

            /***************************** Utility *****************************/
            /**
             * @brief a method to check if this is a zero vector
             *      
             * @return true if zero
             */ 
             bool isZero() const;

            /***************************** Operator Overload *****************************/

            /**
             * @brief overloading operator + 
             * 
             * @param other another vec2
             */
            Vec2 operator+(const Vec2& other) const;

            /**
             * @brief overloading operator - 
             * 
             * @param other another vec2
             */
            Vec2 operator-(const Vec2& other) const;

            /**
             * @brief overloading operator +=
             * 
             * @param other another vec2
             */
            Vec2& operator+=(const Vec2& other);

            /**
             * @brief overloading operator -=
             * 
             * @param other another vec2
             */
            Vec2& operator-=(const Vec2& other);

            /**
             * @brief overloading operator * with scalar
             * 
             * @param scalar the scalar value
             */
            Vec2 operator*(float scalar) const;

            /**
             * @brief overloading operator / with scalar
             * 
             * @param scalar the scalar value
             */
            Vec2 operator/(float scalar) const;

            /**
             * @brief overloading operator *= with scalar
             * 
             * @param scalar the scalar value
             */
            Vec2& operator*=(float scalar);

            /**
             * @brief overloading operator /= with scalar
             * 
             * @param scalar the scalar value
             */
            Vec2& operator/=(float scalar) ;


            /**
             * @brief overloading operator << to call to_string()
             */
            friend std::ostream& operator<<(std::ostream& os, const Vec2& obj) {
                return os << obj.to_string();
            }

            /***************************** To String *****************************/

            /**
             * @brief a method to help people debug this object
             * 
             * @return Brief summary of this object in string
             */
            std::string to_string() const;


            /***************************** Main Methods *****************************/

            /**
             * @brief a method to calculate the length of this vector
             * 
             * @return the length of this vector
             */
            float length() const;

            /**
             * @brief a method to calculate the normalized vector of this vector
             * to put it simply we want a smaller vector that focused more on the direction
             * compared to distance.
             * 
             * @return the normalized vector (magnitude 1 vector)
             */ 
            Vec2 normalized() const;
            
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
            float dot(const Vec2& other) const;

    };

} // namespace retronomicon::lib::math
