#pragma once
#include "EntityManager.h"

class CollisionManager
{
private:
	EntityManager& entityManager;
public:
	CollisionManager(EntityManager& entityM) : entityManager(entityM) {}
	void checkCollision();
	bool checkAABB(const Vector2& position1, const Vector2& size1, const Vector2& position2, const Vector2& size2);
	bool checkOBB(const Vector2& position1, const Vector2& size1, const float rotation1, const Vector2& position2, 
		const Vector2& size2, const float rotation2);
};

