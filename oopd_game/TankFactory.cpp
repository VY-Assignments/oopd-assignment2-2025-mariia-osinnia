#include "TankFactory.h"
#include "PlayerTank.h"
#include "BotTank.h"
#include <iostream>

std::unique_ptr<IEntity> TankFactory::create(std::string& type, std::vector<int>& params)
{
    TankType tankType = parseType(type);
    if (tankType == PLAYER_TANK) return std::make_unique<PlayerTank>(params[0], params[1]);
    else if (tankType == BOT_TANK) return std::make_unique<BotTank>(params[0], params[1]);
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
