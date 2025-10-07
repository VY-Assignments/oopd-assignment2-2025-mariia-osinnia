#pragma once
#include "Tank.h"
class PlayerTank : public Tank
{
private:
	int health = 100;
public:
	PlayerTank(int x, int y, int h = 100) : Tank(x, y), health(h) {}
	void draw(sf::RenderWindow& window) override;
};

