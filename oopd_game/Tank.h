#pragma once
#include "IEntity.h"
#include "IRenderable.h"
#include "IEventHandler.h"
#include "Vector2.h"
class EntityManager;

class Tank : public IEntity, public IRenderable, public IEventHandler
{
private:
	int health = 100;
	bool isAlive = true;
	EntityManager& entityManager;
	Vector2 position = {0, 0};
	Vector2 direction = {0, 0};
	Vector2 size = { 30, 30 };
	float speed = 200.0f;
	float rotation = 0.0f;
	float rotationSpeed = 100.0f;

	float fireCooldown = 0.5f;
	float timeSinceLastShot = fireCooldown;
public:
	Tank(EntityManager& entityM, Vector2& p, float s = 200.0f, Vector2 sz = { 30, 30 }) : entityManager(entityM), position(p), speed(s), size(sz) {}

	virtual RenderData getRenderData() const = 0;
	virtual void onEvent(const EventType& event) = 0;
	virtual void publishEvent(EventType& event) = 0;
	virtual void update(float deltaTime) = 0;
	void shoot();
	void takeDamage(int damage);
	void heal(int healBonus);
	Vector2 getPosition() const override { return position; }
	void setPosition(const Vector2& pos) { position = pos; }

	Vector2 getDirection() const { return direction; }
	void setDirection(const Vector2& dir) { direction = dir;}

	Vector2 getSize() const override { return size; }

	float getSpeed() const { return speed; }

	float getRotation() const { return rotation; }
	void setRotation(float r) { rotation = r; }

	float getRotationSpeed() { return rotationSpeed; }
	void setRotationSpeed(float rSpeed) { rotation = rSpeed; }

	bool isAllive() override { return isAlive; };

	void onCollision(IEntity* entity) override;
};

