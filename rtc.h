#pragma once

#include <cmath>

const float EPSILON = 0.00001f;

class tuple {
public:
	float x;
	float y;
	float z;
	float w;

	tuple(float x, float y, float z, float w) :
		x(x), y(y), z(z), w(w) {}


};

tuple point(float x, float y, float z) {
	return tuple(x, y, z, 1.0);
}

tuple vector(float x, float y, float z) {
	return tuple(x, y, z, 0.0);
}

bool equal(float a, float b) {
	return (abs(a - b) < EPSILON);
}
