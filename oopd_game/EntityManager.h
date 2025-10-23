#pragma once
#include <vector>
#include <memory>
#include "IEntity.h"
#include "Tank.h"
#include "Projectile.h"
#include "InteractiveObject.h"

class EntityManager
{
private:
	std::vector<std::unique_ptr<IEntity>> entities;
public:
	EntityManager(){}
	void addEntity(std::unique_ptr<IEntity> entity);
	std::vector<std::unique_ptr<IEntity>>& getEntities();
	void clear();
	void updateAll(float deltaTime);
};

