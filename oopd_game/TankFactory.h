#pragma once
#include "IEntityFactory.h"
#include <memory>
enum TankType {
	PLAYER_TANK,
	BOT_TANK,
	UNKNOWN_TANK
};
class TankFactory : public IEntityFactory
{
private:
	std::unique_ptr<IEntity> create(std::string& type, std::vector<int>& params) override;
	static TankType parseType(std::string& type);
};

