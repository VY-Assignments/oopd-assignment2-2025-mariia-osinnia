#pragma once
#include "IEntity.h"
#include "InteractiveObject.h"
#include "Vector2.h"
class Mine : public InteractiveObject
{
private:
	int damage = 10;
public:
	Mine(Vector2& p, int d = 10) : InteractiveObject(p), damage(d){}


	void onEvent(const EventType& event) override;
	void publishEvent(EventType& event) override;
	void update(float deltaTime) override;
	void interact(Tank* tank) override;
};

