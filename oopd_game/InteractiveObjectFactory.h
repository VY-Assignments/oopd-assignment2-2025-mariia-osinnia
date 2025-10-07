#pragma once
#include "IEntityFactory.h"

enum InteractiveObjectType {
	MINE,
	HEALTH_PACK,
	UNKNOWN_OBJECT
};
class InteractiveObjectFactory : public IEntityFactory
{
private:
	std::unique_ptr<IEntity> create(std::string& type, std::vector<int>& params) override;
	static InteractiveObjectType parseType(std::string& type);
};

