#include "EntityManager.h"

void EntityManager::addEntity(std::unique_ptr<IEntity> entity)
{
	newEntities.push_back(std::move(entity));
}

std::vector<std::unique_ptr<IEntity>>& EntityManager::getEntities()
{
	return entities;
}

void EntityManager::clear()
{
	entities.clear();
	newEntities.clear();
}

void EntityManager::updateAll(float deltaTime)
{
	for (auto& entity : entities) {
		entity->update(deltaTime);
	}

	if (!newEntities.empty()) {
		for (auto& e : newEntities)
			entities.push_back(std::move(e));
		newEntities.clear();
	}

	entities.erase(std::remove_if(entities.begin(), entities.end(), [](const std::unique_ptr<IEntity>& e) {
		return !e->isAllive();
		}), entities.end());
}

PlayerTank* EntityManager::getPlayer()
{
	for (auto& entity : entities) {
		if (PlayerTank* player = dynamic_cast<PlayerTank*>(entity.get())) {
			return player;
		}
	}
	return nullptr;
}

BotTank* EntityManager::getBot()
{
	for (auto& entity : entities) {
		if (BotTank* player = dynamic_cast<BotTank*>(entity.get())) {
			return player;
		}
	}
	return nullptr;
}
