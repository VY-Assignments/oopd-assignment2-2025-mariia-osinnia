#pragma once
#include <memory>
#include "IEntity.h"

class IEntityFactory {
public:
	virtual std::unique_ptr<IEntity> create(std::string& type, std::vector<int>& params) = 0;
};