#pragma once
#include "IEntity.h"
#include "IEventHandler.h"
#include "Vector2.h"
#include "IRenderable.h"
class Tank;

class InteractiveObject : public IEntity, public IEventHandler, public IRenderable
{
private:
	Vector2 position{0,0};
	float rotation = 0;
	Vector2 size{10,10};
	bool isAlive = true;
	float lifeTime = 5.0f;
	float age = 0.0f;
public:
	InteractiveObject(Vector2& p) : position(p) {}
	void update(float deltaTime) override;
	virtual void onEvent(const EventType& event) = 0;
	virtual void publishEvent(EventType& event) = 0;
	bool isAllive() override { return isAlive; };
	void onCollision(IEntity* entity) override;
	virtual void interact(Tank* tank) = 0;

	Vector2 getPosition() const override { return position; };
	float getRotation() const override { return rotation; }
	Vector2 getSize() const override { return size; };

	RenderData getRenderData() const = 0;
};

