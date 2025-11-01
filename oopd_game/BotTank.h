#pragma once
#include "Tank.h"
#include "PlayerTank.h"

class BotTank : public Tank
{
private:
	std::string type = "botTank";
	PlayerTank* targetPlayer = nullptr;
public:
	BotTank(EntityManager& entityM, EventManager& eventM, const Vector2& position) : Tank(entityM, eventM, position) {}
	RenderData getRenderData() const override;
	void onEvent(const EventType& event) override;
	void publishEvent(const EventType& event) override;
	void update(float deltaTime) override;
	void findPlayer();
	void facePlayer(Vector2& direction, float deltaTime);

	void setTarget(PlayerTank* player) { targetPlayer = player; }
};

