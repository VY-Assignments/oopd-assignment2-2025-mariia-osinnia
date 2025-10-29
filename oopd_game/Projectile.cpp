#include "Projectile.h"
#include "Tank.h"
#include "Obstacle.h"

void Projectile::update(float deltaTime)
{
	position += direction * speed * deltaTime;
	age += deltaTime;
	if (age >= lifeTime) {
		isAlive = false;
	}
}

RenderData Projectile::getRenderData() const
{
	RenderData renderData;
	renderData.position = position;
	renderData.shape = sprite;
	renderData.size = size;
	renderData.color = color;
	return renderData;
}

void Projectile::onCollision(ICollidable* other)
{
	if (Tank* tank = dynamic_cast<Tank*>(other)) {
		tank->takeDamage(damage);
		isAlive = false;
	}
	else if (Obstacle* obstacle = dynamic_cast<Obstacle*>(other)) {
		isAlive = false;
	}
}
