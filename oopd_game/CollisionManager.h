#pragma once
#include "EntityManager.h"
#include "ICollidable.h"
#include "Map.h"

class CollisionManager
{
private:
	EntityManager& entityManager;
	std::vector<ICollidable*> collidable;
	Map& map;
public:
	CollisionManager(EntityManager& entityM, Map& m) : entityManager(entityM), map(m) {}
	void checkCollision();
	bool checkOBB(const Vector2& position1, const Vector2& size1, const float rotation1, const Vector2& position2, 
		const Vector2& size2, const float rotation2);
	void getCollidable();
};

