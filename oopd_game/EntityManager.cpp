#include "EntityManager.h"

void EntityManager::addEntity(std::unique_ptr<IEntity> entity)
{
	entities.push_back(std::move(entity));
}
