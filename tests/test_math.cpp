#include <catch2/catch_test_macros.hpp>
#include "retronomicon/lib/math/point.h"

TEST_CASE("Point addition works", "[math]") {
    using namespace retronomicon::lib::math;

    Point p1{1, 2};
    Point p2{3, 4};
    Point result = p1 + p2;

    REQUIRE(result.getX() == 4);
    REQUIRE(result.getY() == 6);
}

TEST_CASE("Point substraction works", "[math]") {
    using namespace retronomicon::lib::math;

    Point p1{5, 6};
    Point p2{3, 4};
    Point result = p1 - p2;

    REQUIRE(result.getX() == 2);
    REQUIRE(result.getY() == 2);
}

TEST_CASE("Calculate Distance works", "[math]") {
    using namespace retronomicon::lib::math;

    Point p1{0, 6};
    Point p2{0, 4};
    float result = p1.calculateDistance(p2);

    REQUIRE(result == 2.0);

    Point p3{6, 6};
    Point p4{9, 10};
    result = p3.calculateDistance(p4);

    REQUIRE(result == 5.0);

    Point p5{7, 0};
    Point p6{5, 0};
    result = p5.calculateDistance(p6);

    REQUIRE(result == 2.0);
}



TEST_CASE("Point to Vector convertion works", "[math]") {
    using namespace retronomicon::lib::math;

    Point p1{5, 6};

    Vec2 v1 = p1.toVec2();

    REQUIRE(v1.x == 5);
    REQUIRE(v1.y == 6);
}


TEST_CASE("Vector addition works", "[math]") {
    using namespace retronomicon::lib::math;

    Vec2 v1{2, 3};
    Vec2 v2{4, 5};
    Vec2 v3 = v1+v2;

    REQUIRE(v3.x == 6);
    REQUIRE(v3.y == 8);

    v2 += v1;

    REQUIRE(v3.x == 6);
    REQUIRE(v3.y == 8);
}

TEST_CASE("Vector substraction works", "[math]") {
    using namespace retronomicon::lib::math;

    Vec2 v1{2, 3};
    Vec2 v2{4, 5};
    Vec2 v3 = v2-v1;

    REQUIRE(v3.x == 2);
    REQUIRE(v3.y == 2);

    v2 -= v1;

    REQUIRE(v2.x == 2);
    REQUIRE(v2.y == 2);
}
