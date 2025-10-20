#include "EntityManager.h"

void EntityManager::addEntity(std::unique_ptr<IEntity> entity)
{
	entities.push_back(std::move(entity));
}

std::vector<std::unique_ptr<IEntity>>& EntityManager::getEntities()
{
	return entities;
}

std::vector<Tank*> EntityManager::getTanks()
{
	std::vector<Tank*> tanks;
	for (auto& entity : entities) {
		if (Tank* tank = dynamic_cast<Tank*>(entity.get())) {
			tanks.push_back(tank);
		}
	}
	return tanks;
}

std::vector<Projectile*> EntityManager::getProjectiles()
{
	std::vector<Projectile*> projectiles;
	for (auto& entity : entities) {
		if (Projectile* projectile = dynamic_cast<Projectile*>(entity.get())) {
			projectiles.push_back(projectile);
		}
	}
	return projectiles;
}

std::vector<InteractiveObject*> EntityManager::getInteractiveObjects()
{
	std::vector<InteractiveObject*> interactiveObjects;
	for (auto& entity : entities) {
		if (InteractiveObject* interactiveObject = dynamic_cast<InteractiveObject*>(entity.get())) {
			interactiveObjects.push_back(interactiveObject);
		}
	}
	return interactiveObjects;
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
