#pragma once
#include "Tank.h"
class BotTank : public Tank
{
private:
	std::string sprite = "rectangle";
	std::string color = "red";
public:
	BotTank(EntityManager& entityM, Vector2& position) : Tank(entityM, position) {}
	RenderData getRenderData() const override;
	void onEvent(const EventType& event) override;
	void publishEvent(EventType& event) override;
	void update(float deltaTime) override;
};

