#pragma once
#include "IEntityFactory.h"
#include <memory>
#include "Vector2.h"
enum TankType {
	PLAYER_TANK,
	BOT_TANK,
	UNKNOWN_TANK
};
class TankFactory : public IEntityFactory
{
private:
	std::unique_ptr<IEntity> create(std::string& type, Vector2& position) override;
	static TankType parseType(std::string& type);
};

