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

	inline bool is_point() {
		return w == 1.0;
	}

	inline bool is_vector() {
		return w == 0.0;
	}

	tuple operator+(tuple a) {
		x += a.x;
		y += a.y;
		z += a.z;
		w += a.w;
		return *this;
	}

	tuple operator-(tuple a) {
		x -= a.x;
		y -= a.y;
		z -= a.z;
		w -= a.w;
		return *this;
	}

	bool operator==(const tuple& a) const {
		return (x == a.x && y == a.y && z == a.z && w == a.w);
	}
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


