#pragma once
#include "IEntity.h"
#include "InteractiveObject.h"
class Mine : public InteractiveObject
{
private:
	int damage = 10;
public:
	Mine(int x, int y, int d = 10) : InteractiveObject(x, y), damage(d){}

};

