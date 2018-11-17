#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "rtc.h"

TEST_CASE("tuple should return a tuple instance") {
	tuple t(-3, 2, 1, 1);

	REQUIRE(t.x == -3);
	REQUIRE(t.y == 2);
	REQUIRE(t.z == 1);
}

TEST_CASE("point should return a tuple with w = 1.0") {
	tuple p = point(-3, 2, 1);

	REQUIRE(p.w == 1.0);
}

TEST_CASE("vector should return a tuple with w = 0.0") {
	tuple v = vector(-3, 2, 1);

	REQUIRE(v.w == 0.0);
	REQUIRE(equal(v.w, 0.0));
}
