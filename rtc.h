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

	inline tuple operator+(tuple a) {
		x += a.x;
		y += a.y;
		z += a.z;
		w += a.w;
		return *this;
	}

	inline tuple operator-(tuple a) {
		x -= a.x;
		y -= a.y;
		z -= a.z;
		w -= a.w;
		return *this;
	}

	inline tuple operator-() {
		x = -x;
		y = -y;
		z = -z;
		w = -w;
		return *this;
	}

	inline tuple operator*(float a) {
		x *= a;
		y *= a;
		z *= a;
		w *= a;
		return *this;
	}

	inline tuple operator/(float a) {
		x /= a;
		y /= a;
		z /= a;
		w /= a;
		return *this;
	}

	inline bool operator==(const tuple& a) const {
		return (x == a.x && y == a.y && z == a.z && w == a.w);
	}
};

inline tuple point(float x, float y, float z) {
	return tuple(x, y, z, 1.0);
}

inline tuple vector(float x, float y, float z) {
	return tuple(x, y, z, 0.0);
}

inline bool equal(float a, float b) {
	return (std::abs(a - b) < EPSILON);
}

inline float magnitude(tuple t) {
	return sqrt(t.x*t.x + t.y*t.y + t.z*t.z + t.w*t.w);
}

inline tuple normalize(tuple t) {
	float m = magnitude(t);

	return tuple(
			t.x / m,
			t.y / m,
			t.z / m,
			t.w / m);
}

inline float dot(tuple a, tuple b) {
	return a.x * b.x +
		a.y * b.y +
		a.z * b.z +
		a.w * b.w;
}

inline tuple cross(tuple a, tuple b) {
	return vector(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x);
}
