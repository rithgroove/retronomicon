#include <catch_test_macros.hpp>
#include "retronomicon/lib/math/point.h"

TEST_CASE("Point addition works", "[math]") {
    using namespace retronomicon::lib::math;

    Point p1{1, 2};
    Point p2{3, 4};
    Point result = p1 + p2;

    REQUIRE(result.x == 4);
    REQUIRE(result.y == 6);
}