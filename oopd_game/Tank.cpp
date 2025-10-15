#include "Tank.h"
#include "Projectile.h"

void Tank::update(float deltaTime)
{
	timeSinceLastShot += deltaTime;
}

void Tank::shoot()
{
	if (timeSinceLastShot >= fireCooldown) {
		entityManager.addEntity(std::make_unique<Projectile>(position, direction));
		timeSinceLastShot = 0.0f;
	}
}

bool Tank::isAllive()
{
	return true;
}



