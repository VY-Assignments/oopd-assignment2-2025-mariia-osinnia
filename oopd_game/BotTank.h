#pragma once
#include "Tank.h"
class BotTank : public Tank
{
private:
	int health = 100;
	std::string sprite = "rectangle";
	std::string color = "red";
public:
	BotTank(Vector2& position, int h = 100) : Tank(position), health(h) {}
	RenderData getRenderData() const override;
	void onEvent(const EventType& event) override;
	void publishEvent(EventType& event) override;
	void update(float deltaTime) override;
};

