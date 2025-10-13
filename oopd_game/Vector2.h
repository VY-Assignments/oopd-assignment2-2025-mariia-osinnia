#pragma once

struct Vector2 {
	float x, y;

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
		if (x != other.x || y != other.y) return true;
		else return false;
	}
};