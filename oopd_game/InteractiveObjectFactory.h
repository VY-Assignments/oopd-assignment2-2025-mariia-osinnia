#pragma once
#include "IEntityFactory.h"
#include "Vector2.h"

enum InteractiveObjectType {
	MINE,
	HEALTH_PACK,
	UNKNOWN_OBJECT
};
class InteractiveObjectFactory : public IEntityFactory
{
private:
	std::unique_ptr<IEntity> create(std::string& type, Vector2& position) override;
	static InteractiveObjectType parseType(std::string& type);
};

