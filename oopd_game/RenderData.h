#pragma once
#include "Vector2.h"
#include <string>
struct RenderData {
	Vector2 position{};
	Vector2 size{1, 1};
	std::string color = " ";
	std::string shape = " ";
	float rotation = 0.0f;
};