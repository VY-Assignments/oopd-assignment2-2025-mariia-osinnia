#include "EntityManager.h"

void EntityManager::addEntity(std::unique_ptr<IEntity> entity)
{
	entities.push_back(std::move(entity));
}

std::vector<std::unique_ptr<IEntity>>& EntityManager::getEntities()
{
	return entities;
}

void EntityManager::clear()
{
	entities.clear();
}

void EntityManager::updateAll(float deltaTime)
{
	for (auto& entity : entities) {
		entity->update(deltaTime);
	}

	entities.erase(std::remove_if(entities.begin(), entities.end(), [](const std::unique_ptr<IEntity>& e) {
		return !e->isAllive();
		}), entities.end());
}
