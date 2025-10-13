#pragma once
#include "IEntity.h"
#include "IRenderable.h"
#include "IEventHandler.h"
#include "Vector2.h"

class Tank : public IEntity, public IRenderable, public IEventHandler
{
private:
	Vector2 position = {0, 0};
	Vector2 direction = {0, 0};
	Vector2 size = { 30, 30 };
	float speed = 200.0f;
	float rotation = 0.0f;
	float rotationSpeed = 100.0f;
public:
	Tank(Vector2& p, float s = 200.0f, Vector2 sz = { 30, 30 }) : position(p), speed(s), size(sz) {}

	virtual RenderData getRenderData() const = 0;
	virtual void onEvent(const EventType& event) = 0;
	virtual void publishEvent(EventType& event) = 0;
	virtual void update(float deltaTime) = 0;

	Vector2 getPosition() const { return position; }
	void setPosition(const Vector2& pos) { position = pos; }

	Vector2 getDirection() const { return direction; }
	void setDirection(const Vector2& dir) { direction = dir;}

	Vector2 getSize() const { return size; }

	float getSpeed() const { return speed; }

	float getRotation() const { return rotation; }
	void setRotation(float r) { rotation = r; }

	float getRotationSpeed() { return rotationSpeed; }
	void setRotationSpeed(float rSpeed) { rotation = rSpeed; }
};

