#pragma once
#include "Vector2.h"
#include "IEntity.h"
#include "IRenderable.h"

class Projectile : public IEntity, public IRenderable
{
private:
	int damage = 10;
	float speed = 600.0f;
	Vector2 direction = {0, 0};
	Vector2 position = { 0, 0 };
	std::string sprite = "rectangle";
	Vector2 size = { 5, 5 };
	std::string color = "yellow";
	float lifeTime = 2.0f;
	float age = 0.0f;
	bool isAlive = true;
public:
	Projectile(Vector2& pos, Vector2& dir) : position(pos), direction(dir){}

	void update(float deltaTime) override;
	RenderData getRenderData() const override;
	bool isAllive() override;
};

