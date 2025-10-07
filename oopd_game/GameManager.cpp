#include "GameManager.h"
#include "IEntityFactory.h"

void GameManager::init() {
	std::vector<int> params = { 10, 10 };
	std::string type = "player";
	entityManager.addEntity(tankFactory.create(type, params));

	std::vector<int> params1 = { 20, 20 };
	std::string type1 = "bot";
	entityManager.addEntity(tankFactory.create(type1, params1));
}