#include "Projectile.h"
#include "Tank.h"

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

void Projectile::onCollision(IEntity* entity)
{
	if (Tank* tank = dynamic_cast<Tank*>(entity)) {
		tank->takeDamage(damage);
		isAlive = false;
	}
}
