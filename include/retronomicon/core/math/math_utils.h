#pragma once
#include <type_traits>

namespace retronomicon::core::math {

    /**
     * @brief Clamp a value between a minimum and maximum.
     * 
     * @tparam T Numeric type (must support comparison operators)
     * @param value The value to clamp.
     * @param min The lower bound.
     * @param max The upper bound.
     * @return Clamped value in range [min, max].
     */
    template<typename T>
    constexpr T clamp(const T& value, const T& min, const T& max) {
        static_assert(std::is_arithmetic_v<T>, "clamp requires a numeric type");
        return (value < min) ? min : (value > max ? max : value);
    }

} // namespace retronomicon::core::math