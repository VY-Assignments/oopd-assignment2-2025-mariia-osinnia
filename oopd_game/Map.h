#pragma once
#include <vector>
#include "Obstacle.h"
#include <memory>
class Map
{
private:
	std::vector<std::unique_ptr<ICollidable>> obstacles;
public:
	Map() {
		obstacles.push_back(std::make_unique<Obstacle>(
			Vector2{ 200, 300 }, Vector2{ 200, 30 }
		));
	}
	const std::vector<std::unique_ptr<ICollidable>>& getObstacles() const {
		return obstacles;
	}
};

