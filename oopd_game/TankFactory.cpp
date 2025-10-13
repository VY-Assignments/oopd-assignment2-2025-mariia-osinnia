#include "TankFactory.h"
#include "PlayerTank.h"
#include "BotTank.h"
#include <iostream>

std::unique_ptr<IEntity> TankFactory::create(std::string& type, Vector2 & position)
{
    TankType tankType = parseType(type);
    if (tankType == PLAYER_TANK) return std::make_unique<PlayerTank>(position);
    else if (tankType == BOT_TANK) return std::make_unique<BotTank>(position);
    else {
        std::cout << "Unknown tank type" << std::endl;
        return nullptr;
    }
}

TankType TankFactory::parseType(std::string& type)
{
    if (type == "player") return PLAYER_TANK;
    else if (type == "bot") return BOT_TANK;
    else return UNKNOWN_TANK;
}
