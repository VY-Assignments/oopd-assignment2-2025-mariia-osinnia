#pragma once
#include "Tank.h"
class BotTank : public Tank
{
private:
	int health = 100;
public:
	BotTank(int x, int y, int h = 100) : Tank(x, y), health(h) {}
	void draw(sf::RenderWindow& window) override;
};

