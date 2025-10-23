#pragma once
#include "IEntity.h"
#include "Vector2.h"

class IEntityFactory {
public:
	virtual std::unique_ptr<IEntity> create(std::string& type, Vector2 & position) = 0;
};