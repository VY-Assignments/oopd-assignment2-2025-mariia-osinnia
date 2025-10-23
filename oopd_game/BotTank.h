#pragma once
#include "Tank.h"
#include "PlayerTank.h"

class BotTank : public Tank
{
private:
	std::string sprite = "rectangle";
	std::string color = "red";
	PlayerTank* targetPlayer = nullptr;
public:
	BotTank(EntityManager& entityM, EventManager& eventM, Vector2& position) : Tank(entityM, eventM, position) {}
	RenderData getRenderData() const override;
	void onEvent(const EventType& event) override;
	void publishEvent(EventType& event) override;
	void update(float deltaTime) override;

	void setTarget(PlayerTank* player) { targetPlayer = player; }
};

