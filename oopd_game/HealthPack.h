#pragma once
#include "IEntity.h"
#include "InteractiveObject.h"
#include "Vector2.h"
class HealthPack : public InteractiveObject
{
private:
	int healthBonus = 10;
public:
	HealthPack(Vector2& p, int bonus = 10) : InteractiveObject(p), healthBonus(bonus){}

	void onEvent(const EventType& event) override;
	void publishEvent(EventType& event) override;
	void update(float deltaTime) override;
	void interact(Tank* tank) override;
};

