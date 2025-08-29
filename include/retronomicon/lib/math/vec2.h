#pragma once
#include <ostream>
#include <cmath>

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
            float x{0.0f}, y{0.0f}; // because Vec2 values changes a lot we put it in public

            /***************************** Constructor *****************************/

            /**
             * @brief default constructor (0,0)
             */
            constexpr Vec2() = default;
 
            /**
             * @brief constructor (x,y)
             * 
             * @param x value
             * @param y value
             */
            constexpr Vec2(float x, float y) : x(x), y(y) {}

            /***************************** Utility *****************************/
            /**
             * @brief a method to check if this is a zero vector
             *      
             * @return true if zero
             */ 
            [[nodiscard]] constexpr bool isZero() const noexcept { return x == 0.0f && y == 0.0f;}

            /***************************** Operator Overload *****************************/

            /**
             * @brief overloading operator + 
             * 
             * @param other another vec2
             */
            constexpr Vec2 operator+(const Vec2& other) const noexcept{
                return Vec2(x + other.x, y + other.y);
            }

            /**
             * @brief overloading operator - 
             * 
             * @param other another vec2
             */
            constexpr Vec2 operator-(const Vec2& other) const noexcept{
                return Vec2(x - other.x, y - other.y);
            }

            /**
             * @brief overloading operator +=
             * 
             * @param other another vec2
             */
            constexpr Vec2& operator+=(const Vec2& other) noexcept{
                x += other.x; y += other.y;
                return *this;
            }

            /**
             * @brief overloading operator -=
             * 
             * @param other another vec2
             */
            constexpr Vec2& operator-=(const Vec2& other) noexcept{
                x -= other.x; y -= other.y;
                return *this;
            }

            /**
             * @brief overloading operator * with scalar
             * 
             * @param scalar the scalar value
             */
            constexpr Vec2 operator*(float scalar) const noexcept{
                return Vec2(x * scalar, y * scalar);
            }

            /**
             * @brief overloading operator / with scalar
             * 
             * @param scalar the scalar value
             */
            constexpr Vec2 operator/(float scalar) const noexcept{
                return Vec2(x / scalar, y / scalar);
            }

            /**
             * @brief overloading operator *= with scalar
             * 
             * @param scalar the scalar value
             */
            constexpr Vec2& operator*=(float scalar) noexcept {
                x *= scalar; 
                y *= scalar;
                return *this;
            }

            /**
             * @brief overloading operator /= with scalar
             * 
             * @param scalar the scalar value
             */
            constexpr Vec2& operator/=(float scalar) noexcept{
                x /= scalar;
                y /= scalar;
                return *this;                
            }

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
            [[nodiscard]] std::string to_string() const;


            /***************************** Main Methods *****************************/

            /**
             * @brief a method to calculate the length of this vector
             * 
             * @return the length of this vector
             */
            [[nodiscard]] constexpr float length() const noexcept{
                return std::sqrt(x * x + y * y);
            }

            /**
             * @brief a method to calculate the normalized vector of this vector
             * to put it simply we want a smaller vector that focused more on the direction
             * compared to distance.
             * 
             * @return the normalized vector (magnitude 1 vector)
             */ 
            [[nodiscard]] constexpr Vec2 normalized() const noexcept{
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
            [[nodiscard]] constexpr float dot(const Vec2& other) const noexcept{        
                return x * other.x + y * other.y;
            }

    };

} // namespace retronomicon::lib::math
