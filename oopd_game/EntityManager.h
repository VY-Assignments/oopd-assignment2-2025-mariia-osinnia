#pragma once
#include <vector>
#include <memory>
#include "IEntity.h"
class EntityManager
{
private:
	std::vector<std::unique_ptr<IEntity>> entities;
public:
	EntityManager(){}
	void addEntity(std::unique_ptr<IEntity> entity);
	const std::vector<std::unique_ptr<IEntity>>& getEntities(){
		return entities;
	}
};

