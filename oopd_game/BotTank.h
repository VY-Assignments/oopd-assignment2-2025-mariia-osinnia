#pragma once
#include "Tank.h"
#include "PlayerTank.h"
#include "Map.h"

class BotTank : public Tank
{
private:
	std::string type = "botTank";
	PlayerTank* targetPlayer = nullptr;
	Map* map = nullptr;
	const std::vector<std::unique_ptr<ICollidable>>* obstacles = nullptr;

	bool seesPlayer = false;
	float loseTimer = 0.0f;

	bool isPathBlocked();          
	void checkVision(float deltaTime);
	void updateChase(float deltaTime);
	void updatePatrol(float deltaTime);
	bool lineIntersects(Vector2& a1, Vector2& a2, Vector2& b1, Vector2& b2);
public:
	BotTank(EntityManager& entityM, EventManager& eventM, const Vector2& position) : Tank(entityM, eventM, position) {
	}
	RenderData getRenderData() const override;
	void onEvent(const EventType& event) override;
	void publishEvent(const EventType& event) override;
	void update(float deltaTime) override;
	void findPlayer();
	bool facePlayer(Vector2& direction, float deltaTime);

	void setTarget(PlayerTank* player) { targetPlayer = player; }
	void setMap(Map* m);
};

