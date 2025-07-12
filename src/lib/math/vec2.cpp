#include "retronomicon/lib/math/vec2.h"
#include <cmath>

/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::math {
    // Vector addition/subtraction
    Vec2 Vec2::operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 Vec2::operator-(const Vec2& other) const {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2& Vec2::operator+=(const Vec2& other) {
        x += other.x; y += other.y;
        return *this;
    }

    Vec2& Vec2::operator-=(const Vec2& other) {
        x -= other.x; y -= other.y;
        return *this;
    }

    // Scalar multiplication/division
    Vec2 Vec2::operator*(float scalar) const {
        return Vec2(x * scalar, y * scalar);
    }

    Vec2 Vec2::operator/(float scalar) const {
        return Vec2(x / scalar, y / scalar);
    }

    Vec2& Vec2::operator*=(float scalar) {
        x *= scalar; y *= scalar;
        return *this;
    }

    Vec2& Vec2::operator/=(float scalar) {
        x /= scalar; y /= scalar;
        return *this;
    }

    // Magnitude and normalization
    float Vec2::length() const {
        return std::sqrt(x * x + y * y);
    }

    Vec2 Vec2::normalized() const {
        float len = length();
        if (len == 0.0f) return Vec2(0, 0);
        return *this / len;
    }

    float Vec2::dot(const Vec2& other) const {
        return x * other.x + y * other.y;
    }

    // Utility
    bool Vec2::isZero() const {
        return x == 0.0f && y == 0.0f;
    }

    friend std::ostream& Vec2::operator<<(std::ostream& os, const Vec2& v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }
}