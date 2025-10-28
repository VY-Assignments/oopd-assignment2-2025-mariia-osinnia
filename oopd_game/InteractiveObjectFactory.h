#pragma once
#include "IEntityFactory.h"
#include "Vector2.h"
#include <string>

enum InteractiveObjectType {
	MINE,
	HEALTH_PACK,
	UNKNOWN_OBJECT
};
class InteractiveObjectFactory : public IEntityFactory
{
private:
	std::unique_ptr<IEntity> create(const std::string& type, const Vector2& position) override;
	static InteractiveObjectType parseType(const std::string& type);
};

