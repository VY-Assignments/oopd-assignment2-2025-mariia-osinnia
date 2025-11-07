#pragma once
#include <cmath>

struct Vector2 {
	float x, y;

	Vector2() : x(0), y(0) {}
	Vector2(float x_, float y_) : x(x_), y(y_) {}

	float length() const {
		return std::sqrt(x * x + y * y);
	}

	Vector2 operator-(const Vector2& other) const {
		return { x - other.x, y - other.y };
	}

	Vector2 operator/(float scalar) const {
		return { x / scalar, y / scalar };
	}

	Vector2 normalized() const {
		float len = length();
		if (len == 0) {
			return Vector2(0, 0);
		}
		return Vector2(x / len, y / len);
	}

	Vector2 operator*(float scalar) const {
		return{ x * scalar, y * scalar };
	}

	Vector2 operator*=(float scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2 operator+(const Vector2& other) const {
		return{ x + other.x, y + other.y };
	}

	Vector2 operator+=(const Vector2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2 operator-=(const Vector2& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	bool operator!=(const Vector2& other) {
		if (x != other.x || y != other.y) {
			return true;
		}
		else {
			return false;
		}
	}
};