#pragma once
#include "Vector2.h"
#include <string>
struct RenderData {
	Vector2 position{0, 0};
	Vector2 size{1, 1};
	std::string type = " ";
	float rotation = 0.0f;
};