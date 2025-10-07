#pragma once
#include "IEntity.h"
class InteractiveObject : public IEntity
{
private:
	int xPosition = 0;
	int yPosition = 0;
public:
	InteractiveObject(int x, int y) : xPosition(x), yPosition(y) {}
	void update(sf::Event event) override;
};

