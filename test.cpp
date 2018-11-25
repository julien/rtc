#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "rtc.h"

TEST_CASE("Tuple should return a tuple instance") {
	tuple t(-3, 2, 1, 1);

	REQUIRE(t.x == -3);
	REQUIRE(t.y == 2);
	REQUIRE(t.z == 1);
}

TEST_CASE("Point should return a tuple with w=1.0") {
	tuple t = point(-3, 2, 1);

	REQUIRE(t.w == 1.0);
	REQUIRE(equal(t.w, 1.0));
	REQUIRE(t.is_point());
}

TEST_CASE("Vector should return a tuple with w=0.0") {
	tuple t = vector(-3, 2, 1);

	REQUIRE(t.w == 0.0);
	REQUIRE(equal(t.w, 0.0));
	REQUIRE(t.is_vector());
}

TEST_CASE("Tuples can be added") {
	tuple a1 = tuple(3, -2, 5, 1);
	tuple a2 = tuple(-2, 3, 1, 0);

	tuple a3 = a1 + a2;

	REQUIRE(a3.x == 1);
	REQUIRE(a3.y == 1);
	REQUIRE(a3.z == 6);
	REQUIRE(a3.w == 1);
}

TEST_CASE("Tuples can be subtracted") {
	tuple a1 = point(3, 2, 1);
	tuple a2 = point(5, 6, 7);
	tuple a3 = a1 - a2;
	tuple a4 = vector(-2, -4, -6);

	REQUIRE(a3.x == a4.x);
	REQUIRE(a3.y == a4.y);
	REQUIRE(a3.z == a4.z);
	REQUIRE(a3.w == a4.w);
	REQUIRE(a3 == a4);
}

TEST_CASE("Substracting a vector from a point") {
	tuple p = point(3, 2, 1);
	tuple v = vector(5, 6, 7);

	tuple a1 = p - v;
	tuple a2 = point(-2, -4, -6);

	REQUIRE(a1 == a2);
}

TEST_CASE("Subtracting two vectors") {
	tuple v1 = vector(3, 2, 1);
	tuple v2 = vector(5, 6, 7);

	REQUIRE(v1 - v2 == vector(-2, -4, -6));
}

TEST_CASE("Subtracting a vector from the zero vector") {
	tuple zero = vector(0, 0, 0);
	tuple v = vector(1, -2, 3);

	REQUIRE(zero - v == vector(-1, 2, -3));
}

TEST_CASE("Negating a tuple") {
	tuple a = tuple(1, -2, 3, -4);

	REQUIRE(-a == tuple(-1, 2, -3, 4));
}

TEST_CASE("Multiplying a tuple by a scalar") {
	tuple a = tuple(1, -2, 3, -4);

	REQUIRE(a * 3.5 == tuple(3.5, -7, 10.5, -14));
}

TEST_CASE("Multiplying a tuple by a fraction") {
	tuple a = tuple(1, -2, 3, -4);

	REQUIRE(a * 0.5 == tuple(0.5, -1, 1.5, -2));
}


TEST_CASE("Dividing a tuple by a scalar") {
	tuple a = tuple(1, -2, 3, -4);

	REQUIRE(a / 2 == tuple(0.5, -1, 1.5, -2));
}

TEST_CASE("Computing the magnitude of vector(1, 0, 0)") {
	tuple v = vector(1, 0, 0);

	REQUIRE(magnitude(v) == 1);
}

TEST_CASE("Computing the magnitude of vector(0, 1, 0)") {
	tuple v = vector(0, 1, 0);

	REQUIRE(magnitude(v) == 1);
}

TEST_CASE("Computing the magnitude of vector(0, 0, 1)") {
	tuple v = vector(0, 0, 1);

	REQUIRE(magnitude(v) == 1);
}

TEST_CASE("Computing the magnitude of vector(1, 2, 3)") {
	tuple v = vector(1, 2, 3);

	REQUIRE(equal(magnitude(v), sqrt(14)));
}

TEST_CASE("Computing the magnitude of vector(-1, -2, -3)") {
	tuple v = vector(-1, -2, -3);

	REQUIRE(equal(magnitude(v), sqrt(14)));
}

TEST_CASE("Normalizing vector(4, 0, 0) gives (1, 0, 0)") {
	tuple v = vector(4, 0, 0);

	REQUIRE(normalize(v) == vector(1, 0, 0));
}

TEST_CASE("The magnitude of normalizing vector(1, 2, 3)") {
	tuple v = vector(1, 2, 3);
	tuple n = normalize(v);

	REQUIRE(equal(magnitude(n), 1.0f));
}

TEST_CASE("The dot product of two tuples") {
	tuple a = vector(1, 2, 3);
	tuple b = vector(2, 3, 4);

	REQUIRE(dot(a, b) == 20.f);
}

TEST_CASE("The cross product of two vectors") {
	tuple a = vector(1, 2, 3);
	tuple b = vector(2, 3, 4);

	REQUIRE(cross(a, b) == vector(-1, 2, -1));
	REQUIRE(cross(b, a) == vector(1, -2, 1));
}
