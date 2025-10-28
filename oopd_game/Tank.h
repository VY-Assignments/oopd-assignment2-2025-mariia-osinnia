#pragma once
#include "IEntity.h"
#include "IRenderable.h"
#include "IEventHandler.h"
#include "Vector2.h"
#include "EventManager.h"
class EntityManager;

class Tank : public IEntity, public IRenderable, public IEventHandler
{
private:
	int health = 100;
	bool isAlive = true;
	EntityManager& entityManager;
	EventManager& eventManager;
	Vector2 position = {0, 0};
	Vector2 direction = {0, 0};
	Vector2 size = { 30, 30 };
	float speed = 150.0f;
	float rotation = 0.0f;
	float rotationSpeed = 100.0f;

	float fireCooldown = 0.5f;
	float timeSinceLastShot = fireCooldown;
public:
	Tank(EntityManager& entityM, EventManager& eventM, const Vector2& p) : entityManager(entityM), eventManager(eventM), position(p) {}

	virtual RenderData getRenderData() const = 0;
	virtual void onEvent(const EventType& event) = 0;
	virtual void publishEvent(const EventType& event) = 0;
	virtual void update(float deltaTime) = 0;
	void shoot();
	void takeDamage(int damage);
	void heal(int healBonus);
	void onCollision(IEntity* entity) override;

	Vector2 getPosition() const override { return position; }
	void setPosition(const Vector2& pos) { position = pos; }

	Vector2 getDirection() const { return direction; }
	void setDirection(const Vector2& dir) { direction = dir;}

	Vector2 getSize() const override { return size; }

	float getSpeed() const { return speed; }

	float getRotation() const override { return rotation; }
	void setRotation(float r) { rotation = r; }

	float getRotationSpeed() { return rotationSpeed; }
	void setRotationSpeed(float rSpeed) { rotation = rSpeed; }

	EventManager& getEventManager() { return eventManager; }
	EntityManager& getEntityManager() { return entityManager; }

	bool isAllive() override { return isAlive; };
};

