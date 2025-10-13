#pragma once
#include "IEntity.h"
#include "IEventHandler.h"
#include "Vector2.h"
class InteractiveObject : public IEntity, public IEventHandler
{
private:
	Vector2 position;
public:
	InteractiveObject(Vector2& p) : position(p) {}
	virtual void update(float deltaTime) = 0;
	virtual void onEvent(const EventType& event) = 0;
	virtual void publishEvent(EventType& event) = 0;
};

