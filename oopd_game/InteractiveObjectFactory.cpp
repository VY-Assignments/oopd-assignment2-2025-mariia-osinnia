#include "InteractiveObjectFactory.h"
#include "Mine.h"
#include "HealthPack.h"
#include <iostream>

std::unique_ptr<IEntity> InteractiveObjectFactory::create(std::string& type, std::vector<int>& params)
{
	InteractiveObjectType objectType = parseType(type);
	if (objectType == MINE) return std::make_unique<Mine>(params[0], params[1]);
	else if (objectType == HEALTH_PACK) return std::make_unique<HealthPack>(params[0], params[1]);
	else {
		std::cout << "Unknown interactive object type" << std::endl;
		return nullptr;
	}
}

InteractiveObjectType InteractiveObjectFactory::parseType(std::string& type)
{
	if (type == "mine") return MINE;
	else if (type == "healthPack") return HEALTH_PACK;
	else return UNKNOWN_OBJECT;
}
