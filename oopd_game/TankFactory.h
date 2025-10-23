#pragma once
#include <memory>
#include "Vector2.h"
#include "IEntityFactory.h"
#include "EntityManager.h"
#include "EventManager.h"

enum TankType {
	PLAYER_TANK,
	BOT_TANK,
	UNKNOWN_TANK
};
class TankFactory : public IEntityFactory
{
private:
	EntityManager& entityManager;
	EventManager& eventManager;
	std::unique_ptr<IEntity> create(std::string& type, Vector2& position) override;
	static TankType parseType(std::string& type);
public:
	TankFactory(EntityManager& entityM, EventManager& eventM) : entityManager(entityM), eventManager(eventM){
	}
};

