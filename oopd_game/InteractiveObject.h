#pragma once
#include "IEntity.h"
#include "IEventHandler.h"
#include "Vector2.h"
class Tank;

class InteractiveObject : public IEntity, public IEventHandler
{
private:
	Vector2 position{0,0};
	Vector2 size{1,1};
	bool isAlive = true;
public:
	InteractiveObject(Vector2& p) : position(p) {}
	virtual void update(float deltaTime) = 0;
	virtual void onEvent(const EventType& event) = 0;
	virtual void publishEvent(EventType& event) = 0;
	bool isAllive() override { return isAlive; };
	void onCollision(IEntity* entity) override;
	virtual void interact(Tank* tank) = 0;

	Vector2 getPosition() const override { return position; };
	Vector2 getSize() const override { return size; };

};

