#include "Projectile.h"

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

bool Projectile::isAllive()
{
	return isAlive;
}
