#include "GameManager.h"
#include "IEntityFactory.h"
#include "EventType.h"
#include "Tank.h"
#include "Vector2.h"

void GameManager::init() {
	Vector2 position = { 10, 10 };
	std::string type = "player";
	auto playerTank = tankFactory.create(type, position);
	eventManager.subscribe(EventType::MovingForward, dynamic_cast<IEventHandler*>(playerTank.get()));
	eventManager.subscribe(EventType::MovingBackward, dynamic_cast<IEventHandler*>(playerTank.get()));
	eventManager.subscribe(EventType::TurnLeft, dynamic_cast<IEventHandler*>(playerTank.get()));
	eventManager.subscribe(EventType::TurnRight, dynamic_cast<IEventHandler*>(playerTank.get()));
	eventManager.subscribe(EventType::Stop, dynamic_cast<IEventHandler*>(playerTank.get()));
	eventManager.subscribe(EventType::Shoot, dynamic_cast<IEventHandler*>(playerTank.get()));
	entityManager.addEntity(std::move(playerTank));

	Vector2 position1 = { 50, 50 };
	std::string type1 = "bot";
	entityManager.addEntity(tankFactory.create(type1, position1));
}