#pragma once
#include "IEntity.h"
#include "InteractiveObject.h"
class HealthPack : public InteractiveObject
{
private:
	int healthBonus = 10;
public:
	HealthPack(int x, int y, int bonus = 10) : InteractiveObject(x, y), healthBonus(bonus){}
};

